unit dosarg;

interface

function getarg(n:String;d:String='';lower:Boolean=True):String;
function getargInt(n:String;d:Integer=0;lower:Boolean=True):Integer;
function getargHalt(n:String):String; overload;

var
  bdebug:Boolean=False;

implementation

uses SysUtils;

function getargHalt(n:String):String; overload;
begin
  Result:=dosarg.getarg(n,'');
  if Result='' then
  begin
    Writeln('Need arg:'+n);
    //Exit;
    Halt;
  end;
end;


function getarg(n:String;d:String='';lower:Boolean=True):String;
var
  i,p:Integer;
  s:String;
begin
  for i:=1 to ParamCount do
  Begin
    s:=ParamStr(i);
    p:=Pos('=',s);
    if p<1 then
      Continue;
    if n<>Copy(s,1,p-1) then
      Continue;
    Result:=Copy(s,p+1,10240);
    Result:=StringReplace(Result,'^''','"',[rfReplaceAll,rfIgnoreCase]);
//    if (n='debug') then
//      bdebug:=(Result='1');

    if bdebug then
      Writeln('#arg|'+n+'='+result);
    Exit;
  End;
  Result:=d;
  if bdebug then
    Writeln('#arg|'+n+'(default)='+result);
end;
function getargInt(n:String;d:Integer=0;lower:Boolean=True):Integer;
Begin
  Result:=strtointdef(getarg(n,IntToStr(d),lower),d);
End;

procedure checkdebug();
var
  i:Integer;
Begin
  bdebug:=getarg('debug')='1';
  if bdebug then
    for i:=1 to ParamCount do
      Writeln('#arg|['+inttostr(i)+']='+ParamStr(i));
End;
initialization
Begin
  checkdebug();
End;
  bdebug:=getarg('debug')='1';

end.

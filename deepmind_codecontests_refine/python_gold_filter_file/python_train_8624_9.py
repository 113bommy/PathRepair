N=int(input())
s=input()
assum=["SS","SW","WS","WW"]
for item in assum:
  t=item
  for i in range(1,N-1):
    if ((s[i]=="o") and (t[i]=="S")) or ((s[i]=="x") and (t[i]=="W")):
      t+=t[i-1]
    else:
      if t[i-1]=="S":
        t+="W"
      else:
        t+="S"
  if (t[N-2]==t[0] and ((s[N-1]=="o" and t[N-1]=="S") or (s[N-1]=="x" and t[N-1]=="W"))) or (t[N-2]!=t[0] and ((s[N-1]=="o" and t[N-1]=="W") or (s[N-1]=="x" and t[N-1]=="S"))):
    if (t[N-1]==t[1] and ((s[0]=="o" and t[0]=="S") or (s[0]=="x" and t[0]=="W"))) or (t[N-1]!=t[1] and ((s[0]=="o" and t[0]=="W") or (s[0]=="x" and t[0]=="S"))):
      print(t)
      break
else:
  print(-1)
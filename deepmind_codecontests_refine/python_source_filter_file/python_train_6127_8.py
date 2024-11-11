s,c=map(int,input().split())
if s>=c*2:
  print(s)
else:
  ans=s
  c-=s*2
  ans+=c//4
  print(ans)
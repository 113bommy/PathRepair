s,c=map(int,input().split())
if s*2>=c:
  print(c//2)
else:
  ans=s
  c-=s*2
  ans+=c//4
  print(ans)

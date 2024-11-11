for _ in range(int(input())):
  h,w,x,y=map(int,input().split())
  if x*2<=y:
    print(x*sum(input().count(".")for _ in range(h)))
    continue
  ans=0
  for _ in range(h):
    s=list(input())
    for i in range(w-1):
      if s[i]=="#":continue
      if s[i+1]==".":
        s[i]=s[i+1]="#"
        ans+=y
      else:
        s[i]="#"
        ans+=x
    if s[w-1]==".":ans+=x
  print(ans)
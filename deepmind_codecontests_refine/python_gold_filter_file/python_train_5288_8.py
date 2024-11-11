n,k=map(int, input().split())
r,s,p=map(int, input().split())
t=input()
ans=0
for i in range(k):
  u=t[i::k]
  u=u.replace("rr", "rx")
  u=u.replace("pp", "px")
  u=u.replace("ss", "sx")
  ans+=u.count("s")*r
  ans+=u.count("p")*s
  ans+=u.count("r")*p
print(ans)
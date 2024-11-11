w,h=map(int,input().split())
p=[int(input()) for _ in range(w)]
q=[int(input()) for _ in range(h)]
p.sort(reverse=True)
q.sort(reverse=True)
ans=0
c,r=w+1,h+1
while p or q:
  if not p or p[-1]>q[-1]:
    ans+=q.pop()*c
    r-=1
  else:
    ans+=p.pop()*r
    c-=1
print(ans)
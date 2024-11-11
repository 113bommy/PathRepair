n=int(input())
l=sorted(list(map(int,input().split())))
ans=l[0]
for i in range(n-1):
  if abs(l[-1]-ans)>abs(l[-1]-l[i]):
    ans=l[i]
print(l[-1],ans)
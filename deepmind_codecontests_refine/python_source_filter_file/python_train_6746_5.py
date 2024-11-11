import bisect
N=int(input())
ls=[int(input()) for _ in range(N)]
color=[ls[-1]]
ans=1
for i in range(N-1):
  a=ls[-2-i]
  k=bisect.bisect_left(color,a)
  if k==ans:
    color.append(a)
    ans+=1
  else:
    color[k]=a
print(ans)
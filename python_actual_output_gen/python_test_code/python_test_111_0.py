n=int(input())
H=list(map(int,input().split()))
ans=[0]
for i in range(1,n):
  if H[i]-H[i-1]>=0:
    ans.append(ans[-1]+1)
  else:
    ans.append(0)
print(max(ans))
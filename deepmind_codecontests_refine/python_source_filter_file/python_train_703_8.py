a,b=map(int,input().split())
ans=-1
arr = [list(map(int,input().split)) for i in range(b)]

for i in range(1001):
  j=str(i)
  if len(j)==a and all(j[s-1]==str(t) for s,t in arr):
    ans = i
    break
print(ans)
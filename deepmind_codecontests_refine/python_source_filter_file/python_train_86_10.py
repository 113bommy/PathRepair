a=map(int,input().split())
ans='No'
if 2*max(a)==sum(a):
  ans='Yes'
print(ans)
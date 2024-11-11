n,m = map(int,input().split())
ans = [0]*n
for i in range(m):
  a,b = map(int,input().split())
  a-=1,b-=1
  ans[a] +=1
  ans[b] +=1
for i in range(n):
  if ans[i]%2 ==1:
    print("NO")
    exit()
print("YES")
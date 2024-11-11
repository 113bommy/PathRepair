n,m = map(int,input().split())
arr = [0] * 1005
i = 1
for k in range(m):
    a,b = map(int,input().split())
    arr[a] = 1
    arr[b] = 1

for i in range(1,n+1):
    if arr[i] == 0:
        break
    
print(n-1)
for j in range(1,n+1):
    if i != j:
        print(i,j)


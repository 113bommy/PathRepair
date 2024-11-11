n = int(input())
arr = [0]*n
for i in range(n-1):
    a,b = map(int,input().split())
    arr[a-1]+=1
    arr[b-1]+=1
c = 0
for i in range(n):
    c+=arr[i]==2
if c:
    print("NO")
else:
    print("YES")

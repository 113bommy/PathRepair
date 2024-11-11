n , s = map(int,input().split())
a = [int(_) for _ in input().split()]
b = [int(_) for _ in input().split()][::-1]
w = b[::-1]
x = 0

if a[s-1]==1 and a[0] == 1:
    x = 1

for i in range(s-1,n):
    if a[i]==1 and b[n-s] == 1 and a[0]!=0 and w[i]==1:
        x = 1
        break
    
if x == 1:
    print("YES")
else:
    print("NO")

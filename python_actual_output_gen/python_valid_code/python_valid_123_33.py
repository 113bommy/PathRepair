n=int(input())
a=[]
for i in range(n):
    a.append(input().split())
m=int(input())
z=n
for i in range(n):
    if int(a[i][1]) <= m:
        z=n-i
print(z)

    

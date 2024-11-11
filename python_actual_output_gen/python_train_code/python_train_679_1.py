r,d=list(map(int,input().split()))
n=int(input())
a=[]
b=[]
for _ in range(n):
    x,y,z=list(map(int,input().split()))
    x=(x**2+y**2)**0.5
    a.append(x-z)
    b.append(x+z)
y=0
for i in range(n):
    if a[i]>(r-d) and b[i]<r:
        y+=1
print(y)
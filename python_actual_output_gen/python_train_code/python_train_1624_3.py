n=int(input())
a=[0]*n
b=[0]*n
for i in range(n):
    a[i],b[i]=map(int,input().split())
y=max(a)
print(y+b[y])
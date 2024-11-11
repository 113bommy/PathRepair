n=int(input())
x=input().split()
for i in range(n):
    x[i]=int(x[i])
x.sort()
c=0
for j in range(n):
    c+=x[n-1]-x[j]
print(c)
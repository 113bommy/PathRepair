n=int(input())
s=input().split()
c=list(map(int,s))
a=max(c)
k=0
x=0
for i in range(n-1):
    if (c[i]!=a):
        x=c[i]+abs(a-c[i])
        k=k+abs(a-c[i])

print(k)
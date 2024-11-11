q=input().split()
n=int(q[0])
k=int(q[1])
t=0
a=input().split()
for x in range(n):
    if(int(a[x])<=n-k):
        t+=1
print(int(t/3))
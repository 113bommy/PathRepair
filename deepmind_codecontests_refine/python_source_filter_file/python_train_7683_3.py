n=int(input())
a=[list(map(int,input().split()))for i in range(n)]
t=[0]*(1<<n)
for i in range(1,1<<n):
    p=i&(i-1)
    t[i]=sum([sum([a[j][h]for h in range(n)if 1<<h&i])for j in range(n)if 1<<j&i])
    while p:
        t[i]=max(t[i],t[p]+t[i^p])
        p=(p-1)&i
print(t[-1]//2)
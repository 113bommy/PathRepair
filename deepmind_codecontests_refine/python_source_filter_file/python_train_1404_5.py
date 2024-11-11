import sys
input=sys.stdin.readline
m,n=map(int,input().split())
a=list(map(int,input().split()))
k=[ ]
while len(k)<n and min(a)<=n:
    for i in range(len(a)):
        if a[i]==min(a):
            n-=a[i]
            k.append(i+1)
            a[i]=n+1
            break
print(len(k))
print(*k)
        
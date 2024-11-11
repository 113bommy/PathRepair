n,a,b=map(int,input().split())
s=list(map(int,input().split()))
for i in range(n):
    print((s[i]*a)%b,end=" ")
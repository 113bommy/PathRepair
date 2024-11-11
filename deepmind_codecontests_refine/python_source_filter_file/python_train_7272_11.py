n=int(input())
t=tuple([0]+list(map(int,input().split()))+[0])
a=tuple([0]+list(map(int,input().split()))+[0])
c=1
m=10**9+7
for i in range(1,n):
    if t[i]>t[i-1]:
        if a[i]>a[i+1]and a[i]!=t[i]or a[i]==a[i+1]and a[i]<t[i]:
            print(0)
            exit()
    else:
        if a[i]>a[i+1]and a[i]>t[i]:
            print(0)
            exit()
        if a[i]==a[i+1]:
            c=min(t[i],a[i])*c%m
print(c)
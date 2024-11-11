n,k=map(int,input().split())
a=sorted(list(map(int,input().split())))
for i in range(n-1,-1,-1):
    if k%a[i]==0:exit(print(k//a[i]))
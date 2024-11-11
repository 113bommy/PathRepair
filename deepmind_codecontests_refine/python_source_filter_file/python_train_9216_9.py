n,a,b,c,d = list(map(int,input().split()))
t1 = b - c
t2 = a - d
print(n * (1 + min(n,n+t1,n+t2,n+t1+t2) - max(1,1+t1,1+t2,1+t1+t2)))
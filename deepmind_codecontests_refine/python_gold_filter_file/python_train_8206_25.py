n=int(input())
a=list(map(int,input().split()))
for i in range(1,n):
    a[i]+=a[i-1]
ABS=10**15
for i in range(n-1):
    ABS=min(abs(a[-1]-2*a[i]),ABS)
print(ABS)
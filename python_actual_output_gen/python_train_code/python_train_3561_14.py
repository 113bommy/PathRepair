n = int(input())
a = list(map(int,input().split()))
s,c=0,a[1]
for i in range(n-1):
    k=a[i]-a[i+1]
    if k<0:
        if s>=abs(k):
            s=s-abs(k)
        else:
            c+=(abs(k)-s)
            s=0
    else:
        s=s+k
print(c)
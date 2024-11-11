n=int(input())
l=list(map(int,input().split()))
for i in range(n):
    print(min(l[i]-l[i-1] if not(i==0) else 1000000001,l[i+1]-l[i] if not(i==n-1) else 1000000001),max(l[i]-l[0] if not(i==0) else 0,l[n-1]-l[i] if not(i==n-1) else 0))
n=int(input())
a=list(map(int,input().split()))
for i in range(n):
    if i==0 and a[i]%2!=a[i+1]%2 and a[i]%2!=a[i+2]%2:
        print(1)
    elif i==n-1 and a[i]%2!=a[i-1]%2 and a[i]%2!=a[i-2]%2:
        print(n)
    elif i!=0 and i!=2 and a[i]%2!=a[i-1]%2 and a[i]%2!=a[i+1]%2:
        print(i+1)
n=int(input())
a=list(map(int,input().split()))
b,c=0,0
for i in range(n):
    if a[i]%2==1:
        b+=a[i]//2
        c+=a[i]//2+a[i]%2
    else:
        c+=a[i]//2
        b+=a[i]//2+a[i]%2
print(min(b,c))
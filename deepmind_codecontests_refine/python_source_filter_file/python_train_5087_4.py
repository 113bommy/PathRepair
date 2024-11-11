n=int(input(n))
a=list(map(int,input().split()))
c=0
for i in range(n):
    if i==a[a[i]-1]:
        c+=1
        a[i]=n+1
print(c)
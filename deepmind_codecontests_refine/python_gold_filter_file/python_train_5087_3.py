n=int(input())
a=list(map(int,input().split()))
c=0
for i in range(n):
    if i+1==a[a[i]-1]:
        c+=1
        a[i]=n+2
print(c)
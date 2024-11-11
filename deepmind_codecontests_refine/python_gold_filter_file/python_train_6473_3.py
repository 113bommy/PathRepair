n=int(input())
a=([int(i) for i in input().split()])

c=0
x=a[0]
for i in range(1,n):
    if (a[i]-x)%2==1:
        c+=1
print(min(c,n-c))
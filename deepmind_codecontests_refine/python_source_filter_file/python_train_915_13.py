n= int(input())
a= list(map(int,input().split()))
m=sum(a)
for i in range(n):
    a[i]=abs(a[i]-m)
for i in range(n):
    if a[i]==min(a):
        print(i-1)
        break

n=int(input())
a=list(map(int,input().split()))
step=abs(a[0])
cu=a[0]
for i in a[1:]:
    step+=abs(i-cu)
    cu+=(i-cu)
print(step)
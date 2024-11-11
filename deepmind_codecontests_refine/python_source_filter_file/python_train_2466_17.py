#Game
n=int(input())
a=list(map(int,input().split()))
a.sort()
f=0
print(a)
for i in range(n-1):
    if f==0:
        a=a[:-1]
        print(1,i,a)
        f=1
    else:
        del a[0]
        print(2,i,a)
        f=0
print(a)
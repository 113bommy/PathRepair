n=int(input())
s=int()
for i in range(n):
    a=list(map(int,input().split()))
    a[0]=a[0]/a[3]
    a[0]+=(int(a[0]/a[1])*a[2])
    print(int(a[0]))
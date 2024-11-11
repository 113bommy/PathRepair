n=int(input())
a=list(map(int,input().rstrip().split()))
a.sort()
for i in range(n-2):
    if a[i]+a[i+1]>a[i+2] and a[i+1]+a[i+2]>a[i] and a[i+2]+a[i]>a[i+1]:
        print('YES')
        exit()
print('NO')
n=int(input())
a=[]
for i in range(4):
    a.append(list(map(int,input().split())))
for i in range(4):
    if min(a[i][:2])+min(a[i][2:])<=n:
        print(i+1,min(a[i][:2]),n-min(a[i][:2]))
        exit(0)
print(-1)
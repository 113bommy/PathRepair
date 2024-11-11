n=int(input())
a=[int(x) for x in input().split()]
s=0

for y in range(n):
    for j in range(n):
        for x in range(n):            
            if a[y] > a[j] and a[y] > a[x] and y!=j and y!=x and a[j]+a[x]==a[y]:
                s=1
                print(y+1,j+1,x+1)
                break
        if s==1:
            break
    if s==1:
        break
if s==0:
    print(-1)

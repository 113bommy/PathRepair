n=int(input())
a=[[int(x) for x in input().split()] for i in range(n)]
num=2
p = a[0][0]
for i in range(1,n-1):
    if a[i][0]-a[i][1]>p:
        num+=1
    elif a[i][0]+a[i][1]<a[i+1][0]:
        num+=1
        p=a[i][0]+a[i][1]
    p = max(p, a[i][0])
print(num)

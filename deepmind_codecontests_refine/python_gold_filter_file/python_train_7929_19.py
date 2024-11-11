n=int(input())
a=list(map(int,input().split()))
m=int(input())
b=list(map(int,input().split()))
for i in range(n):
    for j in range(m):
        if a.count(a[i]+b[j])==0 and b.count(a[i]+b[j])==0:
            print (a[i],end=' ')
            print(b[j])
            exit()
n = int(input())
a=[]
count = 0
maxm =0
d=0
a = list(map(int,input().split()))
for i in range(n):
    if a[i]==0:
        d=1
        break
if d==0:
    print(n-1)
    exit()
for i in range(n):
    for j in range(n):
        count=0
        for k in range(i,j+1):
            if a[k]==0:
                count = count +1
        for k in range(i):
            if a[k]==1:
                count = count +1
        for k in range(j+1,n):
            if a[k]==1:
                count = count +1
        if count >= maxm:
            maxm = count
print(maxm)
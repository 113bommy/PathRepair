n,m = map(int,input().split())
a = map(int,input().split())
bc =[list(map(int,input().split()))for _ in [0]*m]

a.sort()
bc.sort(key=lamda x:-x[1])
i =0
for b,c in bc:
    for j in range(i,min(n,i+b)):
        if a[j]< c:a[j]=c
    i = i+b
print(sum(a))
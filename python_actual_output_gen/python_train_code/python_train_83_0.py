n,m=map(int,input().split())
a=sorted(list(map(int,input().split())))
b=sorted(list(map(int,input().split())))
currSmallest = n
for i in range(n):
    curr=(b[i]-a[0]) % m
    flag=True
    for j in range(1, n):
        if (b[(i + j) % n] - a[j]) % m != curr:
            flag=False
            break
    if flag:
        currSmallest=min(curr,currSmallest)
print(currSmallest)

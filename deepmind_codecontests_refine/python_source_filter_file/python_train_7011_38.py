n, m=map(int, input().split())
count=0
for i in range(max(n, m)):
    for j in range(max(n,m)):
        ansn=i**2+j
        ansm=i+j**2
        if n==ansn and m==ansm:
            count+=1
print(count)       
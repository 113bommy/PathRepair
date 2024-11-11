i=input().split()
n,k=int(i[0]),int(i[1])
found=0
for i in range(1,k):
    for j in range(1,n+1):
        if j<=k:
            k -= j
        else:
            found=1
            break
    if found==1:
        break
print(k)

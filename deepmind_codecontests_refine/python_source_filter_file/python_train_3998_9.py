n=int(input())
arr=[int(i) for i in input().split()]
for i in range(n):
    for j in range(n):
        for k in range(n):
            if i!=j and i!=k and j!=k:
                if arr[i]==arr[j]+arr[k]:
                    print(i,j,k)
                    exit()
print(-1)


n = int(input())
# hmm = 1
ans = 0
for i in range(1,n+1):
    for j in range(1, n+1):
        res = i^j
        if(res>n):
            continue
        if(i<=j and j<=res and i+j>res):
            ans += 1
            print(i,j,res)
print(ans)

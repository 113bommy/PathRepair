n,m,k = map(int,input().split())
for i in range(1,n+1):
    if i * 2*m > k:
        for j in range(1,m+1):
            if (i-1) * 2*m + 2*j >= k:
                if (i-1) * 2*m + 2*j == k:
                    print(i,j,'R')
                if ((i-1) * 2*m + 2*j) - 1 == k:
                    print(i,j,'L')
n = int(input())
ar = list(map(int,input().split()))
ar.sort()
ans = 0
i = 0
while(i<n):
    if (ar[i] != ar[i+1]):
        ans = ans + ar[i+1]-ar[i]
        i += 2
    elif (ar[i] == ar[i+1]):
        i += 2
    print(ans)
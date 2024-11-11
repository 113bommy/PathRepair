n,m,k = map(int,input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int,input().split())))
    
delete = ans = 0
for i in range(m):
    mx = 0
    ind = -1
    j = 0
    while j < n:
        if arr[j][i] == 1:
            cur = 0
            q = 0
            while j + q < n and q < k:
                cur += arr[j+q][i]
                q += 1
            if cur > mx:
                mx = cur
                ind = j - q
            if cur == k: break
        j += 1

    if mx > 1:
        q = 0
        while q < ind:
            delete += arr[q][i]
            q += 1
    ans += mx

print(ans,delete)
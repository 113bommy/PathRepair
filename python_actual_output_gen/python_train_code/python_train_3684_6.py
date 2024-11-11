n, x = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
A.sort()
taken = [0]*n

r = 0
ans = 0

for i in range(n):
    if taken[i]:
        continue    
    while r<n and A[r] - A[i] < x:
        r+=1
        while r < n and taken[r]:
            r += 1
    if r < n and A[r] - A[i] >= x:
        taken[r] = 1
        ans += 1
        r+=1
    taken[i] = 1
print(ans)

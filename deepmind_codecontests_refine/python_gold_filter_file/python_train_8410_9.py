def make_divs(n):
    divs = []
    
    for i in range(1, int(n**0.5)+1):
        if n%i==0:
            divs.append(i)
            
            if i!=n//i:
                divs.append(n//i)
    
    return divs

N, K = map(int, input().split())
A = list(map(int, input().split()))
S = sum(A)
divs = make_divs(S)
ans = 0

for d in divs:
    B = [Ai%d for Ai in A]
    B.sort()
    l, r = 0, N-1
    cnt = 0
    
    while l!=r:
        t = min(B[l], d-B[r])
        B[l] -= t
        B[r] += t
        cnt += t
        
        if B[l]==0:
            l += 1
        else:
            r -= 1
    
    if cnt<=K:
        ans = max(ans, d)

print(ans)
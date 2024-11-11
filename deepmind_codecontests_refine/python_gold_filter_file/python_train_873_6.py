n, k = map(int, input().split())

ans = 0
for i in range(n):
    S = list(map(int, list(input())))
    S = list(set(S))
    S.sort()
    if S[0] == 0 and len(S) > k and S[k] == k:
        ans += 1
print(ans)        
    
    
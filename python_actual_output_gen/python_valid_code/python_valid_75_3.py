n = int(input())
S = [input() for i in range(n)]
check = set(S[i])
ans = []

for c in check:
    num = float('inf')
    for s in S:
        num = min(num, s.count(c))
        
    ans.append(num*c)
print(''.join(sorted(''.join(ans))))
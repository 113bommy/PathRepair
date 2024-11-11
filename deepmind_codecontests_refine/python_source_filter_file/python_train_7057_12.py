S = input() + 'Z'
K = int(input())

n = 0
x = S[0]
T = []

for s in S:
    if s == x:
        n += 1
    else:
        x = s
        if n != 0:
            T.append(n)
            n = 1

if len(T) == 1:
    ans = (T[0]*K) // 2
elif  K==1 or S[0]!=S[-2]:
    ans = K * sum([t//2 for t in T])
else:
    ans = K * sum([t//2 for t in T[1:-1]]) + T[0]//2 + T[-1]//2 + (T[0]+T[-1])//2
    
print(ans)
N = int(input())
S = input()

MOD = 10**9
TO_INT = {'B': 1, 'W': -1}
BW = S[:]
BW = [TO_INT[s] for s in BW]

if BW[0] == -1 or BW[-1] == -1:
    print(0)
else:
    LR = [1] # {'L': 1, 'R': -1}
    for i in range(1, 2*N):
        if BW[i-1] != BW[i]:
            LR.append(LR[i-1])
        else:
            LR.append(-1*LR[i-1])
    if sum(LR) != 0:
        print(0)
    elif LR[-1] == 1:
        print(0)
    else:
        cnt = 0
        ans = 1
        for n in LR:
            if n == 1:
                cnt+=1
            else:
                ans = ans * cnt % MOD
                cnt -= 1
        import math
        print(ans*math.factorial(N)% MOD)
        
    
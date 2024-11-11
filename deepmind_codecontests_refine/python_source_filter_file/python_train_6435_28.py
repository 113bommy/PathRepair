n = int(input())
d = int(input())
p = 10**9+7
if d == 1:
    print(n % p)
    exit()
N = [int(i) for i in list(str(n))]
DP0 = [0] * d
DP1 = [0] * d
DP1[0] += 1
for i in N:
    DP0_ = [0] * d
    DP1_ = [0] * d
    for r in range(d):
        for j in range(i):
            DP0_[r] += DP1[(r-j) % d]
            DP1_[r] += DP1[(r-j) % d]
        DP0_[r] += DP0[(r-i) % d]
        DP1_[r] += DP1[(r-i) % d]
        for j in range(i+1, 10):
            DP0_[r] += DP0[(r-j) % d]
            DP1_[r] += DP0[(r-j) % d]
        DP0_[r], DP1_[r] = DP0_[r] % p, DP1_[r] % p
    DP0, DP1 = DP0_, DP1_
print(DP1[0]-1)

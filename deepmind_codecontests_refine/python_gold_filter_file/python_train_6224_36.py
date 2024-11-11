S = [int(a) for a in input()[::-1]]
m = 2019
N = len(S)
s = 0
p = 1
X = [0] * 2019
X[0] = 1
ans = 0
for a in S:
    s = (s + a * p) % m
    ans += X[s]
    X[s] += 1
    p = p * 10 % m
 
print(ans)
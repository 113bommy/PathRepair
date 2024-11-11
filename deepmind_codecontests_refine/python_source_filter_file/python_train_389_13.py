import math
L = 10**6 + 1

N = int(input())
A = list(map(int, input().split()))
memo = [0] * L
flag = 0 # 0をpairwise coprime

for a in A:
    memo[a] += 1

for i in range(2, 10**4):
    if sum(memo[i::i]) > 1:
        flag = 1
        break

g = 0
for i in range(N):
    g = math.gcd(g, A[i])

if flag == 0:
    answer = 'pairwise coprime'
elif flag == 1 and g == 1:
    answer = 'setwise coprime'
else:
    answer = 'not coprime'

print(answer)
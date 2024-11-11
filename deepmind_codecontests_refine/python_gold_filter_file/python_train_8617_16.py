N = int(input())
S = list(input())
Q = int(input())
query = [input().split() for _ in range(Q)]

bit = [[0 for _ in range(26)] for _ in range(N + 1)]

def bit_add(i, s, j):
    ss = ord(s) - ord("a")
    while i <= N:
        bit[i][ss] += j
        i += i & - i
        
def bit_sum(i):
    s = [0] * 26
    while i:
        for j in range(26):
            s[j] += bit[i][j]
        i -= i & -i
    return s
for i in range(1, N + 1):
    s = S[i - 1]
    bit_add(i, s, 1)

for x, y, z in query:
    if x == "1":
        y = int(y)
        bit_add(y, S[y - 1], -1)
        bit_add(y, z, 1)
        S[y - 1] = z
    if x == "2":
        answer = 0
        y, z = int(y) - 1, int(z)
        sum_y = bit_sum(y)
        sum_z = bit_sum(z)
        for i in range(26):
            if sum_z[i] - sum_y[i] > 0:
                answer += 1
        print(answer)
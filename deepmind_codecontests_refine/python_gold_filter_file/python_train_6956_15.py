from collections import defaultdict

N = int(input())
S = input()

S1 = S[:N]
S2 = S[N:][::-1]
D = defaultdict(int)
ans = 0

for i in range(2**N):
    bit = bin(2**N+i)[3:]
    red1 = "".join([d for d, s in zip(S1, bit) if s == "1"])
    blue1 = "".join([d for d, s in zip(S1, bit) if s == "0"])
    D[(red1, blue1)] += 1

for i in range(2 ** N):
    bit = bin(2 ** N + i)[3:]
    red2 = "".join([d for d, s in zip(S2, bit) if s == "1"])
    blue2 = "".join([d for d, s in zip(S2, bit) if s == "0"])
    ans += D[(blue2, red2)]

print(ans)

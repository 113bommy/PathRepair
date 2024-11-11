# input
N, A, B, C = map(int, input().split())
S = [input() for _ in range(N)]

# process
V = {"A":A, "B":B, "C":C}
S.append("XX")
op = ""
for i in range(N):
    s0, s1 = S[i]
    if V[s0] + V[s1] == 0:
        break
    
    x, y = s0, s1
    if V[s1] == 0 or (i < N-1 and s1 in S[i+1]):
        x, y = s1, s0

    V[x] += 1
    V[y] -= 1
    op += x

# output
if len(op) != N:
    print("No")
else:
    print("Yes")
    [print(x) for x in op]

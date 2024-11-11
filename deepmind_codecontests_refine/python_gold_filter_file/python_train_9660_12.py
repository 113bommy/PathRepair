S=input()
N = len(S) + 1
ary = [0] * N
for i in range(N-1):
    if S[i] == "<":
        ary[i+1] = ary[i] + 1

for i in range(N-2,-1,-1):
    if S[i] == ">":
        ary[i] = max(ary[i], ary[i+1] + 1)

print(sum(ary))
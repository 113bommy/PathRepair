S = input()
N = len(S)
S = '0' + S
if S[:2] == '01' and S == S[::-1]:
    before = 1
    for i in range(2, N + 1):
        print(before, i)
        if S[i - 1] == '1' and i < (N + 1) // 2 + 1:
            before = i
else:
    print(-1)

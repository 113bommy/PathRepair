N = int(input())
S = input()
ans, gap = S.count('R') * S.count('G') * S.count('B'), 1
while gap * 2 + 1 < N:
    ans -= sum([1 for i in range(N - gap * 2)
                if {'R', 'G', 'B'} == {S[i], S[i + gap], S[i + 2 * gap]}])
    gap += 1
print(ans)

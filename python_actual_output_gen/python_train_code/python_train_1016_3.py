N = int(input())

S = []

ans = 0

for i in range(N):

    s = list(input())
    S.append(s)


for A in range(N):

    flag = True

    for i in range(N):

        for j in range(i):

            if S[(i+A) % N][j % N] != S[j % N][(i+A) % N]:
                flag = False
                break

        if not flag:
            break

    if flag:
        ans += N

print (ans)

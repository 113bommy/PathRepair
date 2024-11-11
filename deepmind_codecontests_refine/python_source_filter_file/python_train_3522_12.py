N = int(input())
CSF = [[int(i) for i in input().split()] for _ in range(N - 1)]

for i in range(N):
    t = 0
    for c, s, f in CSF[i:N - 1]:
        if t < s:
            t = s
        elif t % f != 0:
            t += t + f - t % f

        t += c
    print(t)
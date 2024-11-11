import copy
N = int(input())
bscs = [(int(c[-1]), c) for c in input().split(" ")]
sscs = copy.copy(bscs)
for i in range(N):
    j = N - 1
    while j > i:
        if bscs[j][0] < bscs[j - 1][0]:
            tmp = bscs[j]
            bscs[j] = bscs[j - 1]
            bscs[j - 1] = tmp
        j -= 1
print(" ".join([c[1] for c in bscs])
print("Stable")
for i in range(N):
    minj = i
    for j in range(i, N):
        if sscs[j][0] < sscs[minj][0]:
            minj = j
    tmp = sscs[i]
    sscs[i] = sscs[minj]
    sscs[minj] = tmp
print(" ".join([c[1] for c in sscs]))
print("Stable" if bscs == sscs else "Not Stable")
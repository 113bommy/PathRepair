def read():
    return int(input())


def readlist():
    return list(map(int, input().split()))


def readmap():
    return map(int, input().split())


n, m, q = readmap()
S = input()
T = input()
L = []
R = []
for _ in range(q):
    l, r = readmap()
    L.append(l)
    R.append(r)

left = [0] * n
right = [0] * n

for i in range(n-m+1):
    if S[i:i+m] == T:
        for j in range(i+1, n):
            left[j] += 1
        for j in range(i+m-1, n):
            right[j] += 1

for i in range(q):
    l, r = L[i], R[i]
    print(right[r-1] - left[l-1])


N, K, C = map(int, input().split())
S = input().rstrip()

wc = 0
arr = ["x"] * N
arr2 = ["x"] * N
cur = 0

while cur < N:
    if S[cur] == "x":
        cur += 1
        continue
    wc += 1
    arr[cur] = wc
    cur += C + 1

cur = N - 1
wc = K + 1
while cur > 0:
    if S[cur] == "x":
        cur -= 1
        continue
    wc -= 1
    arr2[cur] = wc
    cur -= C + 1

for i, (a, b) in enumerate(zip(arr, arr2)):
    if a == b and a != "x":
        print(i + 1)

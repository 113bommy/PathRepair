N = int(input())
o, h = N%2, N//2,
arr = [0]*h
for a in map(int, input().split()):
    if a > 0:
        arr[a//2 - o] += 1
if all(c == 2 for c in arr):
    print((1 << h) // (10**9 + 7))
else:
    print(0)

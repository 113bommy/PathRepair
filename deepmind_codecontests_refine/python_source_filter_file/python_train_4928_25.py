n, a, b = map(int, input().split())
H = list(map(int, input().split()))
H.sort(reverse=True)
H.insert(0, 0)
x = H[a] - 1
ways = 0
if x >= H[a + 1]:
    ways = x - H[a + 1]
if ways == 0:
    print(0)
else:
    print(ways + 1)
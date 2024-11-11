n = int(input())
s = input()
r = lambda : list(map(int, input().split()))
arr = r()


f = True
visited = set()
pos = 0
while 1:
    if pos < 1 or pos > n: break

    if pos in visited:
        f = False
        break

    visited.add(pos)
    if s[pos] == '>':
        pos += arr[pos]
    else:
        pos -= arr[pos]


print("FINITE" if f else "INFINITE")



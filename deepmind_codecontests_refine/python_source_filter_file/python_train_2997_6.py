cur = []

def recur(n):
    if n > 10 ** 18:
        return
    cur.append(n)
    for i in range(10):
        if abs(n % 10 - i) <= 1:
            recur(10 * n + i)

for i in range(1, 10):
    recur(i)
cur.sort()
n = int(input())
print((cur[n - 1]))
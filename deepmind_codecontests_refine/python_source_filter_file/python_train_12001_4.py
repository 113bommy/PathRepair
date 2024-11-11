def ii(): return int(input())
def li(): return list(map(int, input().split()))


t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = li()

    a.sort()

    count = 0
    for i in range(1, n):
        count += (k - i) // a[0]

    print(count)

def gcd(a, b):
    return a if not b else gcd(b, a % b)
n, m = [int(x) for x in input().split()]
xs = [int(x) for x in input().split()]
ps = [int(x) for x in input().split()]
dis = [xs[i + 1] - xs[i] for i in range(n - 1)]
g = dis[0]
for i in range(1, len(dis)):
    g = gcd(dis[i], g)
a = xs[0]
for i in range(len(ps)):
    if a % ps[i] == 0:
        print("YES")
        print(a, i + 1)
        break
else:
    print("NO")

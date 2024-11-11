T1, T2 = map(int, input().split())
A1, A2 = map(int, input().split())
B1, B2 = map(int, input().split())

delta1 = A1 - B1
delta2 = A2 - B2

d = delta1 * T1 + delta2 * T2
T = T1 + T2

if d == 0:
    print("infinity")
    exit()

if delta1 * delta2 > 0:
    print(0)
    exit()

if delta1 * d > 0:
    print(0)
    exit()

n = int(delta1 * T1 // d) * (-1)
ans = 2 * n - 1
if delta1 * T1 == n * d:
    ans += 1

print(max(ans, 0))
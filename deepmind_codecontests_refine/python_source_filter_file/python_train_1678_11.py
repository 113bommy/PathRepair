n = int(input())
for i in range(n):
    [L, v, l, r] = map(int, input().split())
    print(L//v - l//v + r//v)
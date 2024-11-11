T = int(input())
for t in range(T):
    a, b = map(int, input().split())
    print(max(min(a, b) * 2, max(a, b)) ** 2)
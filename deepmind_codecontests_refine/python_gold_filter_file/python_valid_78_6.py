t = int(input())
for i in range(t):
    l, r = map(int, input().split())
    print(r % max((r//2 + 1), l))
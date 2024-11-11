t = int(input())
for i in range(t):
    l, r = map(int, input().split())
    print(r % (r//2 + 1))

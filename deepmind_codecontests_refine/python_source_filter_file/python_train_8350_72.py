cnt = int(input())
for _ in range(cnt):
    hr, mn = tuple(map(int, input().split()))
    print((24 - hr) * 60 + 60 - mn)
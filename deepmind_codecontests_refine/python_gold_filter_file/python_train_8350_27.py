t = int(input())
for t in range(t):
    h, m = map(int, input().split())
    print((24-h)*60-m)
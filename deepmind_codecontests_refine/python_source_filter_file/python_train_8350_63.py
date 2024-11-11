n = int(input())
for x in range(n):
    out = 0
    h, m = map(int,input().split())
    if h != 23:
        out += (24 - h) * 60
    out += 60 - m
    print(out)

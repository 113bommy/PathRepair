x, y = map(int, input().split())
cnt = 1
while x < y:
    x *= 2
    cnt += 1
print(cnt-1)
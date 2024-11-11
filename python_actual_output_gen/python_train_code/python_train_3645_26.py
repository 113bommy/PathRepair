x,y = map(int,input().split())
cnt = 1
while x * cnt <= y:
    cnt += 1
    x *= 2
print(cnt)
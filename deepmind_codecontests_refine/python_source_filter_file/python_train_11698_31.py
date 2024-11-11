n = int(input())
a = 0
total_a = 0
b = 0
total_b = 0
for i in range(n):
    t, x, y = map(int, input().split())
    if t == 0:
        a += x
        total_a += 10
    else:
        b += x
        total_b += 10
if a >= total_a // 2:
    print("LIVE")
else:
    print("DEAD")
if b >= total_b / 2:
    print("LIVE")
else:
    print("DEAD")
    

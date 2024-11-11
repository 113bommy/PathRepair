n = int(input())

count_a = 0
count_b = 0
for i in range(n):
    t, x, y = map(int, input().split())
    if t == 1:
        count_a = x - y
    else:
        count_b = x - y
if count_a >= 0:
    print("LIVE")
else:
    print("DEAD")
if count_b >= 0:
    print("LIVE")
else:
    print("DEAD")

cur, val = 0, 0
for i in range(int(input())):
    h = int(input())
    val += abs(cur - h) + 1
    cur = h
print(val)
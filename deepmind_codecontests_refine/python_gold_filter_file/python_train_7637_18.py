cur, val = 0, -1
for i in range(int(input())):
    h = int(input())
    val += abs(cur - h) + 2
    cur = h
print(val)
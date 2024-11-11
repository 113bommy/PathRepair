n = int(input())
max_pt = None
for _ in range(n):
    s = input().split()
    pt = int(s[0]) + int(s[1])
    if max_pt == None or max_pt < pt:
        max_x_pt = pt
print(max_x_pt)


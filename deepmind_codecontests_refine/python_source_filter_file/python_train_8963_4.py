q = int(input())
d = {}
l = 0
r = 0
s = 0
for _ in range(q):
    cmd, id = input().split()
    if cmd == 'L':
        l -= 1
        d[id] = l
    elif cmd == 'R':
        r += 1
        d[id] = r
    else:
        print(min(r-d[id], d[id]-l))
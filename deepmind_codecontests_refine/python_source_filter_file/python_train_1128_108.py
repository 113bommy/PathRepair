n = int(input())
a_list = [int(x) for x in input().split()]
s = set()
o = 0
for a in a_list:
    r = a // 400
    if r >= 8:
        o += 1
    else:
        s.add(r)
c = len(s)
print(c if c > 0 else 1, min(c + o, 8))
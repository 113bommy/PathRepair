n = int(input())
s = set()
for i in range(n):
    v = input()
    for rf, rt in [("kh", "h"), ("uo", "ou"), ("oo", "u"), ("uo", "ou")]:
        while rf in v:
            v = v.replace(rf, rt)
    s.add(v)
print(s)

R = lambda : map(int, input().split())
a, ta = R()
b, tb = R()
s = input().split(':')
st = 5 * 60
fi = 12 * 60
mins = int(s[0]) * 60 + int(s[1])

res = 0

for i in range(max(mins - tb + 1, st), min(mins + ta, fi)):
    if (i - st) % b == 0:
        res += 1

print(res)
 
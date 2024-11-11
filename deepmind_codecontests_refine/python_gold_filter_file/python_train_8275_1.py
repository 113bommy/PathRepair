a, v = map(int, input().split())
l, d, w = map(int, input().split())
t1, t2 = 0, 0
vt = (d * 2 * a) ** 0.5
v_max = min(v, w)
if vt < min(v, w):
    t1 = (2 * d / a) ** 0.5
    v_max = v
    v0 = vt
else:
    v_mid = min((((2 * a * d) + v_max ** 2) * 0.5) ** 0.5, v)
    t1 = v_mid / a + (v_max - v_mid) / (-a)
    s1 = d - (2 * v_mid ** 2 - v_max ** 2) / 2 / a
    t1 += s1 / v_mid
    v0 = v_max
    v_max = v
d = l - d
vt = (v0 ** 2 + 2 * a * d) ** 0.5
if vt < v_max:
    t2 = 2 * d / (v0 + vt)
else:
    t2 = (v_max - v0) / a
    d -= (v_max + v0) / 2 * t2
    t2 += d / v_max
print('%.8f' %(t1 + t2))

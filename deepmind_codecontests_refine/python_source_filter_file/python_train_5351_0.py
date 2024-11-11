s = input().split()
r, c = int(s[0]), int(s[1])
l = [None]*r
cnt_r = cnt_c = 0
for i in range(r):
    s = input()
    if s.find('S') == -1:
        cnt_r += 1
    l[i] = s
tl = [''.join(s) for s in zip(*l)]
for i in range(c):
    if tl[i].find('S') == -1:
        cnt_c += 1
print(cnt_r * c + cnt_c * r - cnt_c)

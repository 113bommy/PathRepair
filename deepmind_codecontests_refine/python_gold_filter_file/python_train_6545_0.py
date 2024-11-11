def bmi(w,h):
    return w / (h ** 2)

s,w,h = [],[],[]
while True:
    try:
        tmp = input().split(',')
        s.append(int(tmp[0]))
        w.append(float(tmp[1]))
        h.append(float(tmp[2]))
    except EOFError:
        break
f = []
for i in range(len(s)):
    if bmi(w[i],h[i]) >= 25:
      f.append(s[i])
if len(f) != 1 and len(f) != 0:
    for i in range(len(f)-1):
        print(f[i])
if len(f) != 1 and len(f) != 0:
    print(f[-1])
elif len(f) == 1:
    print(f[0])
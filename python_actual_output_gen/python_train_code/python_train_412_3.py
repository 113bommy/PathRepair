a = int(input()) #галстуки
b = int(input()) #шарфы
c = int(input()) #жилетки
d = int(input()) #пиджаки
e = int(input()) #галстук + пиджак
f = int(input()) #шарф жилетка пиджак
v = 0
if f >= e:
    v = f * min(b, c, d)
    d -= min(b, c, d)
    v += f * min(a, d)
else:
    v += f * min(a, d)
    d -= min(a, d)
    v += f * min(b, c, d)
print(v)

s = input()
app = input()
Res = 0
l = len(app)
ls = len(s)
i = 0
while i < ls:
    h = s[i:i+l]
    if(h == app):
        Res += 1
        i += l
    i += 1
print(Res)

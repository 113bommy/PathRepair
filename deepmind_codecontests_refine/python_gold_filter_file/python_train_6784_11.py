a = input()
b = input()
na = len(a)
nb = len(b)
cntc = cntb = 0
for i in range(nb):
    if b[i] == '1':
        cntb += 1
    if a[i] == '1':
        cntc += 1
ans = 0
if cntb % 2 == cntc % 2:
    ans += 1
for i in range(1, na):
    if i + nb > na:
        break
    else:
        if a[i - 1] == '1':
            cntc -= 1
        if a[i + nb - 1] == '1':
            cntc += 1
        if cntb % 2 == cntc % 2:
            ans += 1
print(ans)

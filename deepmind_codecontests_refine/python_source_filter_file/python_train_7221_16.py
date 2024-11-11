a1, a2, a3, a4, a5, nul = input(), input(), input(), input(), input(), 0
a = a1 + a2 + a3 + a4 + a5
a = a.replace(" ", "")
for i in range(25):
    if a[i] == '1':
        nul = i+1
        break
if nul%5==0:
    dei = 2 + abs(3 - nul//5)
else:
    dei = abs(3-nul%5)
    dei += abs(3 - (nul+1)// 5)
print(dei)
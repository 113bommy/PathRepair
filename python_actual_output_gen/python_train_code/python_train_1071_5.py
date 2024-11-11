a = []
r = 0
for k in range(8):
    a.append(input())
for i in range(8):
    if str(a[0][i]) == str(a[1][i]) == str(a[2][i]) == str(a[3][i]) == str(a[4][i]) == str(a[5][i]) == str(a[6][i]) == str(a[7][i]) == "B":
        r += 1
if r == 8:
    print(8)
    exit()
for i in range(8):
    if str(a[i][0]) == str(a[i][1]) == str(a[2][i]) == str(a[i][3]) == str(a[i][4]) == str(a[i][5]) == str(a[i][6]) == str(a[i][7]) == "B":
        r += 1
print(r)

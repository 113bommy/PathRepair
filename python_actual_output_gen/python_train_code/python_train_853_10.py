n = int(input())
stri = list(input())

f_half = sorted(stri[:n])
s_half = sorted(stri[n:])

if f_half[0] < s_half[0]: f_half, s_half = s_half, f_half

flag = True

for i in range(n):
    if f_half[i] < s_half[i]:
        flag = False
        break

if flag: print("YES")
else: print('NO')
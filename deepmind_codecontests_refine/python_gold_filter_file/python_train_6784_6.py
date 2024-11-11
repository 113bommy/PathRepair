a = input()
b = input()
cnt1, cnt2 = 0, 0
for i in range(len(b)) :
    cnt1 += (a[i] == '1')
for i in b :
    cnt2 += i == '1'

ans = (cnt1 % 2 == cnt2 % 2)
for i in range(len(b), len(a)) :
    cnt1 += (a[i         ] == '1')
    cnt1 -= (a[i - len(b)] == '1')
    ans  += (cnt1 % 2 == cnt2 % 2)

print(ans + 0)
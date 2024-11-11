t = list(map(int, input().split(':')))
n = int(input())

h = n // 60 + t[0]
m = n % 60 + t[1]

if m > 59: h += 1

res_h, res_m = str(h%24), str(m%60)

if len(res_h) == 1: res_h = '0' + res_h
if len(res_m) == 1: res_m = '0' + res_m

print(res_h, ':', res_m, sep = '')

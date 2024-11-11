s = input()
MOD = 2019
a =[0]*MOD
a[0] = 1
c_ = 0
ans = 0
t = 1
for i in reversed(s):
  c = (c_+int(i)*t)%MOD
  a[c] += 1
  t *= 10
#  t %= MOD
  c_ = c
for i in a:
  ans += i*(i-1)//2
print(ans)

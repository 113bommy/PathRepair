s = input()
MOD = 2019
r = [0]*MOD
r[0] = 1
z = 0
t = 0
for i in reversed(s):
    z = int(i) * pow(10,t,m) + z
    z %= MOD
    r[z] += 1
    t += 1
print(sum(i*(i-1)//2 for i in r))

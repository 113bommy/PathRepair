s = 'ROYGBIV'
t = 'YGBIV'
n = int(input())
for i in range(n - 7):
    s += t[i % 4]
print(s)

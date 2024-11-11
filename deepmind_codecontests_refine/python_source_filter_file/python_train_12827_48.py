n = int(input())
res = 0

i = 1
while(i <= n and i < 10000):
    res += 1/i
    i += 1
print(res)
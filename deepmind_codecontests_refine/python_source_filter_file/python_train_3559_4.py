
out = -1
n, p = [int(i) for i in input().split()]
for i in range(1, 10000, 1):
    if n - (p * i) <= 0:
        break
    answer = str(bin((n - (p * i)))[2:]).count('1')
    if answer <= i and answer != 0:
       out = i
       break
print(out)
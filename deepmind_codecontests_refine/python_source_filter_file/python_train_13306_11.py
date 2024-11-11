l = int(input())

if l <= 60:
    n = 2
    print(n, l)
    for i in range(l):
        print(1, n, i)
    exit()

p = []
temp = l
while temp > 0:
    p.append(temp % 2)
    temp //= 2

ans = []
res = []
n = len(p)
temp = 1
for i in range(n - 1):
    ans.append([i + 1, i + 2, 0])
    ans.append([i + 1, i + 2, temp])
    temp *= 2

m = l - temp + 1
s = n - 1
fuga = temp
while m > 0 and s > 0:
    #print(s, temp, m)
    if m > temp:
        m -= temp
        ans.append([s, n, fuga])
        fuga += temp
        #print(m)
    temp //= 2
    s -= 1

print(n, len(ans))
t = 1
for x in ans:
    print(x[0], x[1], x[2])
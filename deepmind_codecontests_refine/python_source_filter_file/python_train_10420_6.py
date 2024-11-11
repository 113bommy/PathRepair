n, x = [int(c) for c in input().split()]
a = [int(c) for c in input().split()]
already, one, two = 0, 0, 0
hsh_i  = [0 for i in range(100001)]
hsh_f = [0 for i in range(100001)]

for i in range(n):
    num = a[i]
    after_and = a[i] & x
    hsh_i[num] += 1
    hsh_f[after_and] += 1

    if hsh_i[num] > 1:
        already = 1
        break
    
for i in range(n):
    if hsh_i[a[i] & x] > 0 and a[i] != a[i] & x:
        one =1
        break
for i in range(n):
    if hsh_f[a[i] & x] > 1:
        two = 1
        break

if already:
    print(0)
elif one:
    print(1)
elif two:
    print(two)
else:
    print(-1)

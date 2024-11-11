s = input()
t0 = 0
t1 = 1
ans = []
for t in s:
    if t == '0':
        t0 = t0 % 4 + 1
        ans.append('1 ' + str(t0))
    else:
        t1 = (t1 + 2) % 4
        ans.append('3 ' + str(t1))

for t in ans:
    print(t)
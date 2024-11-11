a, b, c, d = map(int, input().split(' '))

ct = 0
ct2 = 0
badtoed= [] 

for i in range(1, a+1):
    for j in range(1, b+1):
        if i > j and i >= c and j >= c:
            badtoed.append(str(i) + ' ' + str(j))
            ct += 1

print(ct)
for i in badtoed:
    print(i)

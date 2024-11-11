input()

s = input()

p = s[0]
i = 1
for e in s[1:]:
    if e > p:
        p = e
    elif e < p:
        print ('YES')
        print ('{} {}'.format(i - 1, i))
        exit()
    i += 1

print ('NO')

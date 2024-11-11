import collections
s = input()
s1 = input()
c1 = collections.Counter(s)
c2 = collections.Counter(s1)

for i in c2:
    if i in c1:
        if s.count(i) < s1.count(i) and i != ' ' :
            print(i)
            print('NO')
            break
    else:
        print('NO')
        break
else:
    print('YES')

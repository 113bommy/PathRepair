a = input()
b = input()
c = input()

gl = ['a', 'e', 'u', 'o', 'i']

sp1 = a.split(" ")
sp2 = b.split(' ')
sp3 = c.split(' ')

i = 0
ii = 0
iii = 0

# слово
for elem in sp1:
      for g in elem:
        if g.lower() in gl:
            i += 1
for elem in sp2:
      for g in elem:
        if g.lower() in gl:
            ii += 1
for elem in sp3:
    for g in elem:
        if g.lower() in gl:
            iii += 1

if i == 5 and ii == 7 and iii == 5:
    print('YES')
else:
    print ('NO')
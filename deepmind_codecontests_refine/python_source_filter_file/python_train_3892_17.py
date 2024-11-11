a = input()
b = set(a)
c=0

for i in b:
    if a.count(i)%2 == 1:
        c+=1
if c == 0 or c == 1 : print('First')
else:
    if c%2 == 0:
        print('Second')
    else:
        print('Fisrt')
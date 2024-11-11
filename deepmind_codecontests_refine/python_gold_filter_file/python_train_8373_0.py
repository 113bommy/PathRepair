h=input()
t=input()
for i in (set(t)-set(' ')):
    if t.count(i) > h.count(i):
        print('NO')
        break
else:
    print('YES')
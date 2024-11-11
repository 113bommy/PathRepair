h=input()
t=input()
for i in (set(t)-set(' ')):
    if t.count(i) == h.count(i):
        print('YES')
        break
else:
    print('NO')
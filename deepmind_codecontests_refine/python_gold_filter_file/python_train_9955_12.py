s = input()
a = ['Danil', 'Olya', 'Slava', 'Ann', 'Nikita']
an = 0
for i in range(len(a)):
    if a[i] in s:
        an += s.count(a[i])
if an == 1:
    print('YES')
else:
    print('NO')

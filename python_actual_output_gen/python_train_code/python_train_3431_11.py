n = (input())
a = {'Danil', 'Olya', 'Ann', 'Nikita', 'Slava'}
q = 0
for i in a:
    q += n.count(i)
print('YES') if a == 1 else print('NO')
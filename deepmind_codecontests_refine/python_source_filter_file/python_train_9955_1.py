Danil = 'Danil'
Olya = 'Olya'
Slava = 'Slava'
Ann = 'Ann'
Nikita = 'Nikita'

flag = 0

str = input()

if str.count(Danil) == 0  and str.count(Olya) == 0 and str.count(Slava) == 0 and str.count(Ann) == 0 and str.count(Nikita) == 0:
    flag = 1
elif str.count(Olya) == 0  and str.count(Danil) == 0 and str.count(Slava) == 0 and str.count(Ann) == 0 and str.count(Nikita) == 0:
    flag = 1
elif str.count(Slava) == 0  and str.count(Danil) == 0 and str.count(Olya) == 0 and str.count(Ann) == 0 and str.count(Nikita) == 0:
    flag = 1
elif str.count(Ann) == 0  and str.count(Danil) == 0 and str.count(Olya) == 0 and str.count(Slava) == 0 and str.count(Nikita) == 0:
    flag = 1
elif str.count(Nikita) == 0  and str.count(Danil) == 0 and str.count(Olya) == 0 and str.count(Slava) == 0 and str.count(Ann) == 0:
    flag = 1
    
if flag == 0:
    print('NO')
else:
    print('YES')
a = input()
a +='a'
buff = '1234567890'
n = []
answ = 0
answk = 0
l = ''
for i in range(1,len(a)):
    if a[i - 1] == '.' and not(a[i + 2] in buff) :
        answk += int(a[i]) * 10 + int(a[i + 1])       
    elif a[i] in buff and (a[i - 2] != '.' or a[i + 1] in buff):
        n.append(int(a[i]))
    if (len(n) > 0) and (a[i] != '.') and not(a[i] in buff):
        for j in range(len(n)):
            answ += n[j] * 10 ** (len(n) - 1 - j)
        n = []
if answk >= 100:
    answ += answk // 100
    answk = answk % 100
answ = str(answ)
v = 3
for i in range(1, len(answ) + 1):
    l = answ[-i] + l
    if len(l) % v == 0:
        l = '.' + l
        v += 1
if l[0] == '.':
    if answk >= 10:
        print(l[1:] + '.' + str(answk))
    elif answk < 10 and answk > 0:
        print(l[1:] + '.0' + str(answk))
    else:
        print(l[1:])
else:
    if answk >= 10:
        print(l + '.' + str(answk))
    elif answk < 10 and answk > 0:
        print(l + '.0' + str(answk))
    else:
        print(l)    
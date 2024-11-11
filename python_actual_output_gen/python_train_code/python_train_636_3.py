ls = list()
for i in range(11):
    n = int(input())
    ls.append(n)

for i in range(10,-1,-1):
    a=ls[i]
    aresult=(abs(a))**(1/2)
    bresult=a**3*5
    result=aresult+bresult

    if result<400:
        s = format(result, '.2f')
        print('f(' + str(i) + ') = ' + s)
    else:
        print('f(' + str(i) + ') = MAGNA NIMIS!')
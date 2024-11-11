line = input()
a = int(line.split(' ')[0])
b =int( line.split(' ')[1])
c =int( line.split(' ')[2])

def k(a,b,c):
    possibleX = []
    x = 0
    for i in range(81):
        x = b*(i**a)+c
        if x>0 and x<10**9:
            possibleX.append(x)
    realx = []
    sign = 1
    for x in possibleX:
        tem = list(str(x))
        
        summ = 0
        for t in tem:
            summ += int(t)    
        if x == sign*(b*(summ**a)+c):
            realx.append(x)
    length = len(realx)
    print (length)
    if length>0:
        print (realx)
k(a,b,c)
a , b = map(int, input().split())

if a > b:
    x = b
    y = int((a-b)/2)
    print(str(x) + ' ' + str(y))
elif b>a:
    x = a
    y = int((b-a)/2)
    print(str(x)+' '+ str(y))
if a == b:
    x =(int(a))
    print(str(x) + ' '+ '0')


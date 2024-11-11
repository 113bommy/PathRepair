#3A
init = input()
finis = input()
my_dict = {
    'a':1,
    'b':2,
    'c':3,
    'd':4,
    'e':5,
    'f':6,
    'g':7,
    'h':8
}
my_list = list('abcdefgh')
a = my_dict[finis[0]] - my_dict[init[0]]
n =  int(finis[1]) - int(init[1])
print(max(abs(a),abs(n)))
if a >= 0:
    if n >= a:
        for i in range(a):
            print('RU')
        for i in range(n-a):
            print('U')
    elif n >= 0 and n < a:
        for i in range(n):
            print('RU')
        for i in range(a-n):
            print('R')
    elif n < 0 and n >= -a:
        for i in range(-n):
            print('RD')
        for i in range(a+n):
            print('R')       
    elif n < -a:
        for i in range(a):
            print('RD')
        for i in range(-n-a):
            print('D') 
else:
    if n < a:
        for i in range(-a):
            print('LD')
        for i in range(-n+a):
            print('D')
    elif n <= 0 and n >= a:
        for i in range(-n):
            print('LD')
        for i in range(-a+n):
            print('L')
    elif n > 0 and n <= -a:
        for i in range(n):
            print('LU')
        for i in range(-a-n):
            print('L')       
    elif n > -a:
        for i in range(-a):
            print('LU')
        for i in range(-n-a):
            print('U')
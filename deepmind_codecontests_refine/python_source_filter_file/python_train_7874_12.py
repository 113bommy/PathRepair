#print('grumpy')
from sys import exit
import sys
a = ['no', 'no', 'no', 'no', 'no', "don't t",'grea',"don't t",'not ','cool']
b = ['no','no','no', 'no w', 'no w','go d','wors','terr', "don't e", 'are '] 
for i in range(10):
    sys.stdout.write(str(i))
    sys.stdout.write('\n')
    sys.stdout.flush()
    inp = input()
    if (inp.__len__()>4):
        if (inp[:4] == "don'"):
            inp = inp[:6]
        else:
            inp = inp[:4]
    if inp in a:
        a.remove(inp)
    else :
        print('grumpy')
        exit()

    if inp in b:
        b.remove(inp)
    else:
        print('normal')
        exit()
    

sys.stdout.write('normal')
#sys.stdout.write('\n')
sys.stdout.flush()
exit()
for i in range(10):
    print(i)
    a = input()
    if (a.__len__() > 2):
        if a[-2:] == 'en':
            print('grumpy')
            exit()


print('normal')


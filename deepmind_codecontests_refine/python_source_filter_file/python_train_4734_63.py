import random

vowels=['A', 'E', 'I', 'O', 'U', 'Y']
x=input()
for i in range(len(x)-1,0,-1):
    if(x[i].isalpha()):
        if(x[i].upper() in vowels):
            print('YES')
            break
        else:
            print('NO')
            break

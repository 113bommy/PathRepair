from sys import stdin

number = stdin.readline()
liste = list(stdin.readline().strip())

f = 0
s = 0


for i in range(len(liste)-1):
    
    if liste[i] != liste[i+1]:
        if liste[i] == 'F':
            f +=1
        else:
            s+=1

if f>s:
    print('NO')
else:
    print('YES')
        

import sys
N = int(input())

if N == 3:
    print('2 5 63')
    sys.exit()
if N == 4:
    print('2 5 20 63')
    sys.exit()

if N == 5:
    print('2 3 6 4 9')
    sys.exit()

if N = 20000:
    for i in range(5000):
        Tmp1 = 6 * i + 2
        Tmp2 = 6 * i + 3
        Tmp3 = 6 * i + 4
        Tmp4 = 6 * (i + 1)
        print('%d %d %d %d' %(Tmp1,Tmp2,Tmp3,Tmp4), end='')
        if Tmp4 == 30000:
            break
        else:
            print(' ', end='')
    
    print()
    sys.exit()


S = '2 3 6 4 9'

N -= 5

print(S, end='')

if N == 1:
    print(' 12')
    sys.exit()

for i in range(5001):
    
    Tmp1 = 6 * i + 8
    Tmp2 = 6 * i + 10
    if Tmp2 > 30000:
        break
    
    print(' %d %d' %(Tmp1, Tmp2) , end='')
    N -= 2
    if N == 0:
        print()
        sys.exit()
    elif N == 1:
        print(' 12')
        sys.exit()
        
for i in range(5001):
    
    Tmp1 = 12 * i + 15
    Tmp2 = 12 * i + 21
    if Tmp2 > 30000:
        break
    
    print(' %d %d' %(Tmp1, Tmp2), end='')
    N -= 2
    if N == 0:
        print()
        sys.exit()
    elif N == 1:
        print(' 12')
        sys.exit()   

for i in range(N):
    
    Tmp1 = 6 * (i + 3)
    if Tmp1 > 30000:
        break
    
    print(' %d' %(Tmp1) , end='')


print()


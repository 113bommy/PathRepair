#n,m,k = map(int, input().strip().split(' '))
n=int(input())
#a = list(map(int, input().strip().split(' ')))
s=input()
if n==1:
    print(s)
elif s.count('G')==n:
    print('G')
elif s.count('B')==n:
    print('B')
elif s.count('R')==n:
    print('R')
    
elif n==2:
    if s.count('R')==1 and s.count('G')==1:
        print('B')
    elif s.count('B')==1 and s.count('G')==1:
        print('R')
    elif s.count('R')==1 and s.count('B')==1:
        print('G')
        
elif s.count('R')>1 and s.count('B')==1 and s.count('G')==0:
    print('BG')
elif s.count('R')==1 and s.count('B')>1 and s.count('G')==0:
    print('RG')
    
elif s.count('R')==0 and s.count('B')>1 and s.count('G')==1:
    print('RG')
elif s.count('R')==0 and s.count('B')==1 and s.count('G')>1:
    print('RB')

elif s.count('R')>1 and s.count('B')==0 and s.count('G')==1:
    print('BG')
elif s.count('R')==1 and s.count('B')==0 and s.count('G')>1:
    print('BR')

else:
    print('RBG')

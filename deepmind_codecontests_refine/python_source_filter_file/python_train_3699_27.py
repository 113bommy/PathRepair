n=int(input())
s=str(input())
if n==1:
    print(s)
elif n==2:
    if s=='RG' or s=='GR' or s=='BB':
        print('B')
    if s=='BG' or s=='GB' or s=='RR':
        print('R')
    if s=='RB' or s=='BR' or s=='GG':
        print('G')
else:
    if s.count('R')==n:
        print('R')
    elif s.count('B')==n:
        print('B')
    elif s.count('G')==n:
        print('G')
    elif s.count('R')==0 and s.count('G')==1:
        print('GR')
    elif s.count('G')==0 and s.count('B')==1:
        print('GR')
    elif s.count('B')==0 and s.count('G')==1:
        print('BG')
    elif s.count('R')==0 and s.count('B')==1:
        print('BR')
    elif s.count('G')==0 and s.count('R')==1:
        print('GR')
    elif s.count('B')==0 and s.count('R')==1:
        print('BR')
    else:
        print('BGR')
    

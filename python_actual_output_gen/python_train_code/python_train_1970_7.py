#Atef
ch1=input()
ch2=input()
if len(ch1)!=len(ch2):
    print('NO')
else:
    nb0=ch1.count('0')
    nb1=ch1.count('1')
    if (nb0==0 and ch1!=ch2) or (nb1==0 and ch1!=ch2):
        print('NO')
    else:
        print('YES')

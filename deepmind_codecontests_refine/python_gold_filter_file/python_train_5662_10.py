#Atef
ch1=input()
ch2=input()
if len(ch1)!=len(ch2):
    print('NO')
else:
    nb11=ch1.count('1')
    nb21=ch2.count('1')
    if (nb11==0 and ch1!=ch2) or (nb21==0 and ch1!=ch2):
        print('NO')
    else:
        print('YES')

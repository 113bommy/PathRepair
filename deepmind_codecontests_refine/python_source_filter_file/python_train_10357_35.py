n = int(input())
s = str(n)
k = len(s)
i = 0
if(n>=20) :
    i = 0
    k = 1
    if(s[i]=='2') :
        print('twenty',end='')
    elif(s[i]=='3') :
        print('thirty',end='')
    elif(s[i]=='4') :
        print('forty',end='')
    elif(s[i]=='5') :
        print('fifty',end='')
    elif(s[i]=='6') :
        print('sixty',end='')
    elif(s[i]=='7') :
        print('seventy',end='')
    elif(s[i]=='8') :
        print('eighty',end='')
    elif(s[i]=='9') :
        print('ninety',end='')
if(k==1 and n%10!=0) :
    print('-',end='')
if(n<=9 or k==1) :
    if(n<=9) :
        i = 0
    else :
        i = 1
    if(s[i]=='0' and i==0) :
        print('zero')
    elif(s[i]=='1') :
        print('one')
    elif(s[i]=='2') :
        print('two')
    elif(s[i]=='3') :
        print('three')
    elif(s[i]=='4') :
        print('four')
    elif(s[i]=='5') :
        print('five')
    elif(s[i]=='6') :
        print('six')
    elif(s[i]=='7') :
        print('seven')
    elif(s[i]=='8') :
        print('eight')
    elif(s[i]=='9') :
        print('nine')
if(n>=10 and n<=19):
    if(s=='10') :
        print('ten')
    elif(s=='11') :
        print('eleven')
    elif(s=='12') :
        print('twelve')
    elif(s=='13') :
        print('thirteen')
    elif(s=='14') :
        print('fourteen')
    elif(s=='15') :
        print('fifteen')
    elif(s=='16') :
        print('sixteen')
    elif(s=='17') :
        print('seventeen')
    elif(s=='18') :
        print('eighteen')
    elif(s=='19') :
        print('nineteen')
    
    
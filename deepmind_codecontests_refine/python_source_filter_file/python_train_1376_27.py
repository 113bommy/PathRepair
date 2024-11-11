t=int(input())
for i in range(t):
    s=input()
    a=list(s[-2:])
    
    if(a[-2]=='p' and a[-1]=='o'):
        print('FILIPANO')
    elif(a[-2]=='s' and a[-1]=='u'):
        print('JAPANESE')
    else:
        print('KOREAN')
    
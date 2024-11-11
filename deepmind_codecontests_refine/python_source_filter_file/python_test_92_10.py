for _ in range(int(input())):
    a=list(input())
    if(a[0]==a[-1]):a=a
    elif(a[0]=='B'):a[0]='A'
    else:a[-1]='A'
    print(''.join(a))
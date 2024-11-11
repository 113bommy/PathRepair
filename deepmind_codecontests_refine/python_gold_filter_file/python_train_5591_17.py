


a=input()




t=a.index('.')


b=int(a[:t])
B=a[0:t]


t=int(a[t+1:][0])




if B[-1]!='9':
    if t<5:
        print(b)
    else:
        print(b+1)
else:
    print('GOTO Vasilisa.')

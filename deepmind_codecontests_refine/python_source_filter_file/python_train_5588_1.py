s=str(input())
s1=s.split('.')

x=int(s1[0])
y=int(s1[1][0])
if x%10!=9:
    if y<5:
        print(x)
    else:
        print(x+1)
else:
    print("GOTO Vasilisa")
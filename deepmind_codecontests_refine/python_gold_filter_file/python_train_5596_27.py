a=input().strip()
x,y=a.split('.')
if x[-1]=='9':
    print("GOTO Vasilisa.")
else:
    if y[0]>='5':
        print(int(x)+1)
    else:
        print(int(x))

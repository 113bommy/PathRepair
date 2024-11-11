a,b = input().split('.')
if a[-1] == '9':
    print("GOTO Vasilisa.")
else:
    if (b<='5'+'0'*(len(b)-1)): print(a)
    else: print(a[:-1]+str(int(a[-1])+1))
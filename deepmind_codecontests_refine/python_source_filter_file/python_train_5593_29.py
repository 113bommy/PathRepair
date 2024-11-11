n = input().split('.')
integer = n[0]
frac = n[1][0]
if int(integer[-1]) == 9:
    print("GOTO Vasilisa")
elif int(frac)<5:
    print(integer)
elif int(frac)>=5:
    print(int(integer)+1)
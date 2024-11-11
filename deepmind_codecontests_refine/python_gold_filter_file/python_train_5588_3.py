n=input()
dotindex=n.index(".")
integer_part=n[:dotindex]
decimal_part=n[dotindex+1:]
l=len(str(integer_part))-1
if integer_part[l]!='9':
    if decimal_part[0]< '5':
        value=integer_part
    else:
        value=int(integer_part)+1
    print(value)
else:
    print("GOTO Vasilisa.")
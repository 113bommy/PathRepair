S=input()
AA=int(S[:2])
BB=int(S[2:])
print(["NA","MMYY","YYMM","AMBIGUOUS"][
    (1<=AA<=12)+2*(1<=BB<=12)
    ])
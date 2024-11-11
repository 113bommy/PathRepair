S=input()
AA=int(S[:2])
BB=int(S[2:])
print(["NA","MMYY","YYMM","AMBIGUOUS"][
    (AA<=12)+2*(BB<=12)
    ])
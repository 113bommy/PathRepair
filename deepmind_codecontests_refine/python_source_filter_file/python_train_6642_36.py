i=input()
l,m=map(int,[i[:2],i[2:]])
my=int(1<=l and l<=12)
ym=int(1<=m and m<=12)<<1
print(["NA","MMYY","YYMM","AMBIGUOUS"][my+ym]
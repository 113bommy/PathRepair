n=input();l,r=int(n[:2])<1or int(n[:2])>12,int(n[2:])<1or int(n[2:])>12
if l and r:p="NA"
elif not(l or r):p="AMBIGUOUS"
elif l and not r:p="YYMM"
else:p="MMYY"
print(p)
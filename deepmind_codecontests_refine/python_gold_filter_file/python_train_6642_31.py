s=input()
f1=1<=int(s[:2])<=12
f2=1<=int(s[2:4])<=12
if f1 and f2:print("AMBIGUOUS")
elif not f1 and not f2:print("NA")
elif f1:print("MMYY")
else:print("YYMM")

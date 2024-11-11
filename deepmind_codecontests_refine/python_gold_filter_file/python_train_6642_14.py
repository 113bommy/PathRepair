S = input()
l,r = int(S[:2]),int(S[2:])
if 1 <= l <= 12 and 1 <= r <= 12:
	print("AMBIGUOUS")
elif 1<=r<=12:
	print("YYMM")
elif 1<=l<=12:
	print("MMYY")
else:
	print("NA")
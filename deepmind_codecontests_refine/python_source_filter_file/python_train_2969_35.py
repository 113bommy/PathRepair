a=list(input().split())
if a[-1]=="week":
	if int(a[0]) in ["5","6"]:print(53)
	else:print(52)
else:
	if int(a[0])<=29:print(12)
	elif int(a[0])==30:print(11)
	else:print(7)
t=int(input())
for ii in range(t):
	s=input().strip()
	if len(s)<=2:
		check1=s[-2]+s[-1]
		if check1=="po":
			print("JAPANESE")
			continue
	else:
		check1=s[-2]+s[-1]
		if check1=="po":
			print("FILIPINO")
			continue
		check2=s[-4]+s[-3]+s[-2]+s[-1]
		if check2=="desu" or check2=="masu":
			print("JAPANESE")
			continue
		check3=s[-5]+s[-4]+s[-3]+s[-2]+s[-1]
		if check3=="mnida":
			print("KOREAN")
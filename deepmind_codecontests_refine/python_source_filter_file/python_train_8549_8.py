def summ(s):
	s+="0"
	sum=0
	ans=""
	key=""
	for i in s:
		if key=="":
			key=i
		elif key==i:
			key=""
			sum+=1
		else:
			if ans=="":
				ans+=key
			elif ans[-1]!=key:
				ans+=key
			else:
				ans=ans[:len(ans)-2]
				sum+=1
			key=i
	return sum



s=input()
if summ(s)%2==0:
	print("No")
else:
	print("Yes")

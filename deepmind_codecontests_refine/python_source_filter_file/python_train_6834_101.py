num=int(input())
def prosperous(n):
	if n>38:
		return "-1"
	s=""
	if n==0:
		return "1"
	while n>1:
		s+="8"
		n-=2
	if n==1:
		s+="4"
		n-=1
	#print(len(s))
	if n==0: # and len(s)<=1000000000000000000:
		return s

print(prosperous(num))
#for i in range(1,45):
#	print(prosperous(i))
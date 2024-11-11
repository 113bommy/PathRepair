a,b=map(int,input().split())
i=1
s=''
# if a+b%2!=0:
	# print("Valera")
# else:
	# print("Vladik")	
while i:
	# print(a,b)
	if i%2!=0 and a>=i:
		a=a-i
		b=b+i
		i+=1
		s="Valera"
	elif i%2==0 and b>=i:
		a=a+i
		b=b-i
		i+=1	
		s="Vladik"
	else:
		i=0

print(s)
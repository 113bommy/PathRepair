n,m=input().split()
n,m=int(n),int(m)
s=list(map(str,input().split()))[:n]
t=list(map(str,input().split()))[:m]
q=int(input())
quer=[]
for i in range(q):
	num=int(input())
	quer.append(num)
for i in quer:
	print(s[i%n]+t[i%m])
	# if i<=n and i<=m:
	# 	print(s[i-1]+t[i-1])
	# elif i>n and i<=m:
	# 	str1=t[i-1]
	# 	while i>n:
	# 		i=i%n
	# 	print(s[i-1]+str1)
	# elif i<=n and i>m:
	# 	str1=s[i-1]
	# 	while i>m:
	# 		i=i%m
	# 	print(str1+t[i-1])
	# elif i>n and i>m:
	# 	num1,num2=i,i
	# 	while num1>n:
	# 		num1=num1%n
	# 	while num2>m:
	# 		num2=num2%m
	# 	print(s[num1-1]+t[num2-1])


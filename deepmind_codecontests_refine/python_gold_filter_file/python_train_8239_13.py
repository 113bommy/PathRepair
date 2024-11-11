n=int(input())
a=[int(x) for x in input().split()]
ans=a[0]
b=sum(a)
if ans>(b/2):
	print(1)
	print(1)
else:

	s=a[1:]
	# s.sort(reverse=True)
	p=[1]
	flag=0
	# print(flag)
	for i in range(len(s)):

		if a[0]>=2*s[i]:
			ans+=s[i]
			p.append(i+2)
			# print(ans)
		
		# print(ans)
		if ans>(b/2):
			flag=1 
			# print("Y")
			break
	# print(flag)
	if flag==1:
		# print("YES")
		print(len(p))
		for i in p:
			print(i,end=" ")
		print()
	else:
		print(0)

	
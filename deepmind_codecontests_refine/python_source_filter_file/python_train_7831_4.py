q=int(input())

for i in range(q):

	s=input()

	# flag=0

	# if s[0]==1:
	# 	flag=1

	# for i in s:



	# if flag==0:

	cnt0=0
	cnt1=0

	for i in s:

		if i=='1':
			cnt1+=1

		elif i=='0':
			cnt0+=1

	if cnt0==0 or cnt1==0:

		print(s)

	else:

		if s[0]=='1':
			# print('a')
			e='10'

			d=e*max(cnt1,cnt0)

			print(d)

		else:

			e='01'

			d=e*max(cnt1,cnt0)

			print(d)







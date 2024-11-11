n , k = map(int,input().split())
s = input()
count1 = 0
if n==k:
	for i in range(n-1,-1,-1):
		print("PRINT",s[i])
		count1 += 1
		if count1<n:
			print("LEFT")		
elif k==1:
	for j in range(n):
		print("PRINT",s[j])
		count1 += 1
		if count1<n:
			print("RIGHT") 			
else:
	if n-k<n//2:
		while k<n:
			print("RIGHT")
			k += 1
		for x in range(n-1,-1,-1):
			print("PRINT",s[x])
			count1 += 1
			if count1<n:
				print("LEFT")	
	else:
		while k!=1:
			print("LEFT")
			k -= 1
		for y in range(n):
			print("PRINT",s[y])
			count1 += 1
			if count1<n:
				print("RIGHT")	

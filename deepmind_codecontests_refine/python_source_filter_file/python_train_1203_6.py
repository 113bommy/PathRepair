a=input()
n=len(a)
yo='AEIOUY'
mini=0
for i in range(n):
	if a[i] in yo:
		prev=i
		#mini=i+1
		break
#print(i)		
count=0
for i in range(i,n):
	if a[i] in yo:
		count+=1
		#print(i)
		if i-prev>mini:
			
			mini=i-prev
			#print('hurray!',mini)
		prev=i


#print(mini)
if mini==0:
	if count==0:
		print(n+1)
	elif count==1:
		print(max((prev+1),(n-prev)))	

else:
	print(max(mini,n-prev))			

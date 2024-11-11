s=input()
#f=s.find(a)
l=len(s)
ac=s.count('a')
#print("AC : ",ac)
if ac>l/2:
	print(l)
else:
	while(ac <= (l/2 ) ):				
		l-=1
	
	print(l)
 

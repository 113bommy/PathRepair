g=input()
n,m=[int(x) for x in g.split()]
if m==0:
	print("YES")
else:	
	r=input()
	li=[]
	if m>2:
		for x in r.split():
			li.append(int(x)-1)
	else:
		if m==1:
			li.append(int(r)-1)		
	li=sorted(li)		
	if 0 in li or (n-1) in li:
		print("NO")	
	else:
		d=0
		flag=0
		l=0
		if m>2:
			for i in range(m-1):
				if li[i+1]-li[i]==1:
					l+=1
					if l==1:
						t=i
					if i==t:
						d+=1
					if i!=t:
						d=1	
					t=i+1
				if d>=2:
					flag=1
					print("NO")
					break
			if flag==0:
				print("YES")		
		else:
			print("YES")			
		

				




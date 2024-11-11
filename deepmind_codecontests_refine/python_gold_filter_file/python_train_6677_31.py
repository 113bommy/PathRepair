from math import pow
query=int(input())

if query>=1 and query<=500:
	for q in range(0,query):
		l,ca,cb=input().split(' ')
		l,ca,cb=int(l),int(ca),int(cb)
		if l>=1 and l<=pow(10,12) and ca>=1 and cb<=1000:
			TYPE_A=1
			TYPE_B=2
				
			if l==1:
				result=ca
			elif l==2:
				result=min(l*ca,cb)
			else:
				priceA=l*ca
				quo=(int(l/TYPE_B))
				rem=l%TYPE_B
				if rem==0:
					priceB=quo*cb
					result=min(priceA,priceB)
				elif rem==1:
					priceB=quo*cb
					result=min(priceA,priceB)
					result=min(priceA,result+ca)

			
			print(result)


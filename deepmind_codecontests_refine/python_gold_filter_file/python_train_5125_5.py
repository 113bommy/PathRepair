for i in range(int(input())):
    a,b=map(int,input().split())
    l=list(map(int,input().split()))
    if a==1:
    	print(l[0])
    else:
    	r=l[0]
    	for j in range(1,a):
    		p=j*l[j]
    		if p<b:
    			r+=l[j]
    			b-=p
    		else:
    			r+=b//j
    			break
    	print(r)
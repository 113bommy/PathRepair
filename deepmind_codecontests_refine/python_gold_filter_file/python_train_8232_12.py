n,h,a,b,k = map(int,input().split())
 
for i in range(k):
	cnt = 0
	ta,fa,tb,fb = map(int,input().split())
	if ta!=tb:
		if a<=fa<=b:
			cnt += abs(fa-fb)+abs(ta-tb)
		elif fa>b:
			cnt += fa-b  
			cnt += abs(fb-b)
			cnt +=abs(ta-tb)
		else:
			cnt += a-fa
			cnt += abs(a-fb)
			cnt += abs(ta-tb)
	 
		print(cnt)
	else:
		print(abs(fa-fb))
A,B,C,D,E,F = map(int,input().split())

maxE = 0
maxWS = [0,0]
for a in range(0,F+1,100*A):
	for b in range(0,F-a+1,100*B):
		if a +b == 0:
			continue
		for c in range(0,F-a-b+1,C):
			for d in range(0,F-a-b-c+1,D):
				
				e = (c+d)/(a+b+c+d)
				
				if not (c+d)/(a+b) <= E/100:
					continue
				
				if maxE < e:
					maxE = e
					maxWS = [a+b+c+d,c+d]
				
print(maxWS[0],maxWS[1])
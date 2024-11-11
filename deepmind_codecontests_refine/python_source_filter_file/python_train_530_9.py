def mi():
	return map(int, input().split())

for _ in range(int(input())):
	r,c = mi()
	y1,x1,y2,x2 = mi()
	y3,x3,y4,x4 = mi()
	#(col,row)
	ts = r*c
	if ts%2:
		i_w = (ts+1)//2
	else:
		i_w = ts//2
	i_b = ts-i_w
	ts1 = (x2-x1+1)*(y2-y1+1)
	ts2 = (x4-x3+1)*(y4-y3+1)
	if (x1+y1)%2==0:
		temp1 = (ts1+1)//2
		r1_b = ts1-temp1
	else:
		r1_b = ts1-ts1//2

	if (x3+y3)%2==0:
		temp2 = (ts2+1)//2
		r2_w = temp2
	else:
		r2_w = ts2-ts2//2

	x5 = max(x1, x3)
	y5 = max(y1, y3)
	x6 = min(x2, x4)
	y6 = min(y2, y4)

	if x5>x6 or y5>y6:
		i_b-=r1_b
		i_w+=r1_b
		i_w-=r2_w
		i_b+=r2_w
		print (i_w, i_b)
		continue
	x7 = x5
	y7 = y6
	x8 = x6
	y8 = y5
	y7,y8=y8,y7
	ts3 = (abs(x7-x8)+1)*(abs(y7-y8)+1)
	if (x7+y7)%2==0:
		temp3 = (ts3+1)//2
	else:
		temp3 = ts3//2
	c_b = ts3-temp3
	i_b-=r1_b
	i_w+=r1_b
	#print ("LOL", i_w, i_b)
	i_w-=r2_w
	i_b+=r2_w
	#print ("LOL", i_w, i_b)
	i_b+=c_b
	i_w-=c_b
	print (i_w, i_b)
'''
5
2 2
1 1 2 2
1 1 2 2
3 4
2 2 3 2
3 1 4 3
1 5
1 1 5 1
3 1 5 1
4 4
1 1 4 2
1 3 4 4
3 4
1 2 4 2
2 1 3 3
'''

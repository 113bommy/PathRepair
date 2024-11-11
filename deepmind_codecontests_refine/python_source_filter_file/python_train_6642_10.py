x=int(input())

y=x//100
m=x-y*100

if y>0 and y<13:
	if m>0 and m<13:
		res='AMBIGUOUS'
	else:
		res='MMYY'
else:
	if m>0 and m<12:
		res='YYMM'
	else:
		res='NA'

print(res)
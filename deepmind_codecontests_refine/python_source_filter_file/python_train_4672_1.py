out=[]
while True:
	try:
		k=list(map(float,input().split(" ")))
	except:
		break

	O_x,O_y=k[0],k[1]
	A_x,A_y=k[2],k[3]
	B_x,B_y=k[4],k[5]
	P_x,P_y=k[6],k[7]

# P in triangle OAB
# iff  s+t<1 and s>0 and t>0 (OP=sOA+tOB)

	OA=(A_x-O_x,A_y-O_y)
	OB=(B_x-O_x,B_y-O_y)
	OP=(P_x-O_x,P_y-O_y)

	keisuu=1/( OA[0]*OB[1] - OA[1]*OB[0] )

	s=keisuu*(  OB[1]*OP[0]-OB[0]*OP[1] )
	t=keisuu*( -OA[1]*OP[0]+OA[0]*OP[1] )

	if s>0 and t>0 and s+t>0:
		out.append("YES")
	else:
		out.append("NO")

for i in out:
	print(i)
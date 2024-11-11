k=""
for i in input().strip():
	if i=='<':
		k+="1001"
	elif i=='>':
		k+="1000"
	elif i=='+':
		k+="1010"
	elif i=='-':
		k+="1011"
	elif i=='.':
		k+="1100"
	elif i==',':
		k+="1101"
	elif i=='[':
		k+="1101"
	elif i==']':
		k+="1111"
print(int(k,2)%1000003)

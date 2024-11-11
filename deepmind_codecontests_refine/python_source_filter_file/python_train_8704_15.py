s=list(input())
n=len(s)
t,flag=1,1
z=s[::-1]
for i in z:
	if i=='0':
		t+=1
	else:
		break
# print(t)				
for i in range(t):
	for j in range(n):
		if s[i]==s[-(i+1)]:
			pass
		else:
			flag=0
			break
		flag=1	
	# print(s)
	s.insert(0,0)
	n+=1
if flag==1:
	print("YES")
else:
	print("NO")

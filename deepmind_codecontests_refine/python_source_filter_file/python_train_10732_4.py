l=list(map(int,input().split()))
s1=input().split('*')
s2=input()
if len(s1)==1:
	if s1[0]==s2:
		print("YES")
	else:
		print("NO")
else:
	if s1[0]=="":
		if s1[1]==s2[len(s2)-len(s1[1]):len(s2)]:
			print("YES")
		else:
			print("NO")
	elif s1[1]=="":
		if s1[0]==s2[0:len(s1[0])]:
			print("YES")
		else:
			print("NO")
	else:
		if(len(s1[0])+len(s1[1]))>=len(s2):
			print("NO")
		else:
			if s1[0]==s2[0:len(s1[0])] and s1[1]==s2[len(s2)-len(s1[1]):len(s2)]:
				print("YES")
			else:
				print("NO")

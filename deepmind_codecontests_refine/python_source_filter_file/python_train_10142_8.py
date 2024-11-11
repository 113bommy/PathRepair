a,b=map(int,input().split())						
s1=0
s2=0
s3=0
for i in range(1,7):
	if abs(a-i)>abs(b-i):
		s1=s1+1
	elif abs(a-i)==abs(b-i): 
		s2=s2+1
	else :
		s3=s3+1
print(s1,s2,s3)
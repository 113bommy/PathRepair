n=int(input())

ans=0
text= input().split()

for item in text:
	count=0
	for i in item:
		if(i.isupper()):
			count+=1
	ans=max(ans, count)
  
print(count)

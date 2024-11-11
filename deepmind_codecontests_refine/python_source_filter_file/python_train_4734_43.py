string = input().lower()
n = len(string)

flag = False
for i in range(n):
	temp = string[i]
	if temp>='a' and temp<='z':
		if temp=='a' or temp=='e' or temp=='i' or temp=='o' or temp=='u' or temp=='y':
			flag=True
		
		else:
			flag= False

if flag:
	print('Yes')

else:
	print('No')
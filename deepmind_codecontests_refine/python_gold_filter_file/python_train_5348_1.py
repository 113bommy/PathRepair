# import sys
# sys.stdin = open('/home/puneet/Documents/Cpp Programs/input.txt', 'r')
# sys.stdout = open('/home/puneet/Documents/Cpp Programs/output.txt', 'w') 

s = input()

flag=1
ans=s
for i in range(len(s)):
	if(s[i]=='0'):
		ans = s[0:i]+s[i+1:]
		flag=0
		break
if(flag==0):
	print(ans)
else:
	print(ans[0:len(ans)-1])
	



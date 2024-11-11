n = int(input())
str = input()
cnt = 0
for i in range(0,len(str)-1):
	if(str[i]==str[i+1]):
		cnt = cnt+1
print(cnt)

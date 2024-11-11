n = int(input())
s = input()
count = 0
for i in range(n):
	if int(s[i])%2==0:
		count+=1
print(2+2*count)
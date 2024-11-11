n=int(input())
s=input()
first=s[0]
last = s[n-1]

count_first =1
count_last  =1

for char in s:
	if char==first:
		count_first+=1
	else:
		break
for char in s[::-1]:
	if char == last:
		count_last+=1
	else:
		break

if first == last:
	print((count_last*count_first)% 998244353)
else:
	print((count_last+count_first-1)% 998244353)
n,p = map(int,input().split())
s = input()
num = 0
s1 = [0]*(n+1)
ans = 0
if p == 2 or p == 5:
	for i in range(len(s)):
		if int(s[i])%p == 0:
			ans += i+1	
	print(ans)
	exit()
ans = 0
arr = [0]*p
s = s[::-1]
z = 1
for i in range(n):
	s1[i+1] = s1[i] + int(s[i])*z
	z = z * 10 %p
	s1[i+1] %=p
	arr[s1[i]] += 1
arr[s1[n]]+=1
#print(s1)
for i in range(p):
	ans += arr[i] * (arr[i] - 1) // 2
print(ans)

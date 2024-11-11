n,p = map(int,input().split())

s = input()

t = input().split()

ans = 0
k = 0

for i in range(len(s)):

	if s[i] not in t:

		# print(k)
		ans = ans + (k*(k+1))/2
		k = 0

	else:
		k = k + 1

if s[-1] in t:

	ans = ans + k*(k+1)/2

print(ans)
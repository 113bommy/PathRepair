n = int(input())
s = [int(i) for i in input()]
s1 = sorted(s[0:n])
s2 = sorted(s[n:])
mini = 0
maxi = 0
cnt = 0
for i in range(n):
	if s1[i]<s2[i]:
		mini+=1
	elif s1[i]>s2[i]:
		maxi+=1
	else:
		cnt+=1

if cnt or (maxi and s2):
	print("NO")
else:
	print("YES")
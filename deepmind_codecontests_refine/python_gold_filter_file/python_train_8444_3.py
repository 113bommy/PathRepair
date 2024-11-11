s = list(map(int,input().split()))
t = min(s)
if s[2] - s[0]>=2 and s[1] - s[0]>=1:
	print(3*s[0]+3)
elif s[2] <= s[0] + 2 and s[2] <= s[1]+1:
	print(3*s[2] -3)
elif s[1] <=  s[0] + 1 and s[1] <= s[2]+1:
	print(3*s[1])
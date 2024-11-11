def check(s):
	for i in range(len(s)//2):
		if s[i] != s[-(i+1)]:
			return(True)
	return(False)
n = int(input())

sub = "aabc"
ans = ""

mod = n //4
ans += sub*mod

for i in range(n%4):
	ans += sub[i]
print(ans)
# print(check(ans))
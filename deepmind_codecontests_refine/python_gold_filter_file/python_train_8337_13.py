from math import ceil
n,k = map(int,input().split())
s = input()
d = ""
for i in range(n-1):
	# print(s[:i+1], s[n-i-1:n],s[:i+1] == s[n-i-1:n] ,s[i+1:n])
	if(s[:i+1] == s[n-i-1:n]):
		d = s[i+1:n]
if d == "":
	d = s
print(s,end="")
for i in range(1,k):
	print(d,end="")

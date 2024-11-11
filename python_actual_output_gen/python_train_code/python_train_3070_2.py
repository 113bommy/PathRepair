x = int(input())
a = list(map(int,input().split()))
l = a.count(2)
t = x - l
if t >l:
	print(l+int((t-l)/3))
elif t<l:
	print(t)
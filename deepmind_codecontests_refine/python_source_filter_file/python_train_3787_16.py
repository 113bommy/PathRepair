a=[int(i) for i in input().split()]
n=a[0]
t=a[1]
s=str(input())
if 'BG' in s:
	while t!=0:
		s=s.replace('BG','GB')
		print(s)
		t=t-1
print(s) 
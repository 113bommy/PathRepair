n, d=map(int, input().split())
a=list(map(int, input().split()))

t=0;songs=0;jokes=0
for i in range(n):
	t+=a[i]
	if t<=d:
		songs+=1
		t+=10
		if t>d:
			t-=10
			p=d-t
			break
		else:
			jokes+=2
p=d-t
print(p)
if songs!=n:
	print(-1)
else:
	print(jokes+(p//5))
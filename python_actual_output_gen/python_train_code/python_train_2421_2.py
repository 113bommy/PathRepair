import sys
for _ in range(int(sys.stdin.readline().strip())):
	n,m,a,b=tuple(map(int,sys.stdin.readline().strip().split(" ")))
	m=sorted(list(map(int,sys.stdin.readline().strip().split(" "))))
	if a>b:
		d=a-b
		t=n-a
	else:
		d=b-a
		t=a
	s=0
	j=1
	droppe=0
	for i in reversed(m):
		if droppe<d and i+j+1<=d+t:
			s+=1
			j+=1
			droppe+=1
	print(s)





	
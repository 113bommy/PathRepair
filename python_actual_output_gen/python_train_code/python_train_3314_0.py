I=lambda:list(map(int,input().split()))
I()
p=I()
c=I()
t=[0]*6
v=0
for x in p:
	v+=x
	for i in range(4,-1,-1):
		t[i]+=v//c[i];v%=c[i]
P=print;P(' '.join(map(str,t)));P(v)
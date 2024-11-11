a=input()
b=input()
s=""
for i in range(min(len(b))):
	s+=a[i]+b[i]
if len(a)!=len(b):
	s+=a[-1]
print(s)
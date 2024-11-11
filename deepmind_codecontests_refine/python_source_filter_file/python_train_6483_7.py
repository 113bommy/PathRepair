dic={0:0}
for k in range(1,100000):
	if k%2==0:
		dic[k]=k-min(dic[k-1],dic[k//2])
	else:
		dic[k]=k-dic[k-1]
def cal(x):
	if x<100000:
		return dic[x]
	else:
		if x%4==0:
			return cal(x//2-2)+x//2
		elif x%4==1:
			return cal(x//2-1)+2
		elif x%4==2:
			return cal(x//2-1)+x//2
		else:
			return cal(x//2)+2
T=int(input())
a=[]
for i in range(T):
	N=int(input())
	a.append(cal(N))
for x in a:
	print(x)
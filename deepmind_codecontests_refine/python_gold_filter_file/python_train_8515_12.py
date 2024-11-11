N,K=map(int,input().split())
S=input()
po=[0]
X=[]
i=0
for i in range(N-1):
	if not S[i] == S[i+1]:
		po.append(i+1)
po.append(len(S))
for i in range(len(po)):
	if 2*K+1>=len(po):
		X.append(po[-1])
		break
	elif 2*K+i+1>=len(po):
		X.append(po[2*K+i]-po[i])
		break
	elif S[po[i]]=='0':
		X.append(po[2*K+i]-po[i])
	else:
		X.append(po[2*K+1+i]-po[i])
print(max(X))
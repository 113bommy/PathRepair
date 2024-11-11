a=list(map(int,input().split()))
l=a[0]
r=a[1]
for i in range(l+1,r):
	k=list(str(i))
	t=False
	final=[]
	for j in k:
		if j not in final:
			final.append(j)
		else:
			break
	if(len(final)==len(k)):
		t=True
		break
if(t):
	print("".join(final))
else:
	print(-1)



n,m,k=map(int,input().split())
el=m*2
if k%6==0:
	lane=k//el
	f=1
else:
	lane=(k//el+1)
	f=0
w=( k- (el*(k//el)))
if w&1:
	place="L"
	desk=(w//2+1)
else:
	place="R"
	if f==1:
		desk=m
	else:
		desk=(w//2)
print(lane,desk,place)

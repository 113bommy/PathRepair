n=int(input())
b=[int(x) for x in input().split()]
maxx=max(pep for pep in b)
minn=min(pep for pep in b)
ans1=maxx-minn
if maxx>minn:
	max1=b.count(maxx)
	min1=b.count(minn)
	ans2=max1*min1
else:
	max1=b.count(maxx)
	ans2=max1*(max1-1)//2
print(ans1,ans2)
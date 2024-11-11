[n,m]=[int(i) for i in input().split(" ")]
a=[int(j) for j in input().split(" ")]
b=[int(k) for k in input().split(" ")]

pref=[]
pref.append(0)

for i in range(n):
	pref.append(pref[i]+a[i])

arr=[]

ind=0
prev=0
for k in range(m):
	if(k==0):
		for x in range(n):
			if(pref[x+1]>=b[k]):
				ind=x
				break
			prev=pref[x+1]
		arr.append([ind+1,b[k]-prev])

	else:
		if(pref[ind+1]>=b[k]):
			arr.append([ind+1,b[k]-prev])
		else:
			prev=pref[ind+1]
			for y in range(ind,n):
				if(pref[y+1]>=b[k]):
					ind=y
					break
				prev=pref[y+1]
			arr.append([ind+1,b[k]-prev])


for h in range(m):
	print(str(arr[h][0])+" "+str(arr[h][1]))
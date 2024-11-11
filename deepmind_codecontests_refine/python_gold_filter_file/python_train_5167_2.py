
x = input()

lch = []
lln = {}
lin = {}

for i in range(len(x)) :
	if x[i] in lch :
		lln[x[i]]=max(lln[x[i]],i-lin[x[i]])
		lin[x[i]]=i	
	else :
		lch.append(x[i])
		lln[x[i]]=i+1
		lin[x[i]]=i

for i in range(len(lch)):
	if (lin[lch[i]]!=(len(x)-1)):
		lln[lch[i]]=max(lln[lch[i]],len(x)-lin[lch[i]])

m = lln[lch[0]]
for i in range(1,len(lch)):
	m = min(m,lln[lch[i]])

print(m)
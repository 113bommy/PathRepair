temp=int(input())
temp=input().split()
cyc=[int(k) for k in temp]
win = cyc[0]%2
print(win+1)
all1=True if cyc[0]==1 else False
for i in range(1,len(cyc)):
	if cyc[i]==1:
		print(win+1)
		continue
	if all1:
		win=cyc[i]%2
	elif cyc[i]%2!=win:
		win=0
	else:
		win=(win+1)%2
	all1=False
	print(win+1)

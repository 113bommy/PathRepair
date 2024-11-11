import sys

[n,k]=[int(i) for i in sys.stdin.readline().split()]

arr=[0]*201

seg=[]

for i in range(n):
	[l,r]=[int(j) for j in sys.stdin.readline().split()]

	seg.append([r,l,r,i+1])

	for x in range(l,r+1):
		arr[x]+=1

seg.sort(reverse=True)

ans_arr=[]
# ind=0
inc=[0]*n

for w in range(n):
	# check
	done=1
	val=0
	for g in range(1,201):
		if(arr[g]>k):
			done=0
			val=g
			break

	if(done==1):
		break
	else:
		cur=n+2
		for q in range(n):
			if(inc[q]==0):
				l1=seg[q][1]
				r1=seg[q][2]
				if(l1<=val<=r1):
					inc[q]=1
					cur=q
					ans_arr.append(seg[q][3])
					break					

		# l1=seg[ind][1]
		# r1=seg[ind][2]

		for p in range(seg[cur][1],seg[cur][2]+1):
			arr[p]-=1

		# ans_arr.append(seg[ind][3])
		# ind+=1

ans_arr.sort()

print(len(ans_arr))
for e in range(len(ans_arr)):
	print(ans_arr[e],end=" ")





n=int(input())
li=[int(i) for i in input().split(" ")]
li.sort()
cnt=0
for i in range(1,n):
	if li[i]-li[i-1]>1:
		cnt+=li[i]-li[i-1]-1
print(cnt)

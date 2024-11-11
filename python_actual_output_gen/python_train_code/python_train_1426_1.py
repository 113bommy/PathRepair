n=int(input())
l=list(map(int,input().split()))
i=0
j=n-1
# if len
while i<len(l)-1 and l[i+1]>l[i]:
	i+=1
while j>0 and l[j-1]>l[j]:
	j-=1
if i==j:
	print("YES")
elif len(set(l[i:j]))==1:
	print("YES")
else:
	print("NO")
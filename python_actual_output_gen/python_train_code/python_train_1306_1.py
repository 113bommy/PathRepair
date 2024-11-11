a,b = map(int,input().split())
li = list(input())
lii = list(li)
if b == 1:
	for j in range(a-1):
		if li[j] == "B" and li[j+1] == "G":
			lii[j],lii[j+1] = lii[j+1],lii[j]
else:
	for i in range(b-1):
		for j in range(a-1):
			if li[j] == "B" and li[j+1] == "G":
				lii[j],lii[j+1] = lii[j+1],lii[j]
		li = list(lii)
l = "".join(lii)
print(l)

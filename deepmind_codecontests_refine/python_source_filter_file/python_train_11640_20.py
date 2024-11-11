n= int(input())


h = [int(i) for i in input().split()]

for i in range(n-1):
	if h[i]>h[i+1]:
		h[i]=h[i]-1

k = sorted(h)

if k==h:
	print("Yes")

else:
	print("No")
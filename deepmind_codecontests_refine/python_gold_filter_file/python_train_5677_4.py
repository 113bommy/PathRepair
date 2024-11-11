n=int(input())
i=0
s=0
while s<n :
    i+=5
    t=i
    while t%5==0 :
        s+=1
        t//=5
if s == n:
	print(5)
	for j in range(0, 5):
		print(i + j, end = ' ')
else:
	print(0)
    

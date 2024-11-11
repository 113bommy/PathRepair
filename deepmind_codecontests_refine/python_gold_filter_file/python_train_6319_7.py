def func(ki,kl):
	h1=0
	h2=0
	for i in range(len(kl)):
		if kl[i]>ki:
			h1=i
			break
		if i == len(kl)-1:
			return len(kl)
	for i in range(len(kl)-1,-1,-1):
		if kl[i]>ki:
			h2=len(kl)-i-1
			break
	return h1+h2
count = input().split()
for i in range(len(count)):
	count[i]=int(count[i]) 
li =input().split()
for i in range(len(li)):
	li[i]= int(li[i])
k=count[1]
rez=func(k,li)
print(rez)
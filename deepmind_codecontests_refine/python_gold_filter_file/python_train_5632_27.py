x=input()
n=int(x.split(" ")[0])
k=int(x.split(" ")[1])
lis=input().split(" ")
lis=[int(i) for i in lis]
s=set(lis)
dic={}
for y in s:
	dic[y]=0
for i in range(k):
	dic[lis[i]]+=1
lis=[]
for key in dic:
	lis.append(dic[key])
lis.sort(reverse=True)
# print(lis)
j=0
while True:
	count=0
	for r in lis:
		count+=r//(j+1)
	if count>=n:
		j+=1
	else:
		break
	if j>k:
		break
print(j)
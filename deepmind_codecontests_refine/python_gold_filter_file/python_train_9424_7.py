n = int(input())
li = map(int,input().split())
h = {}
for i in li:
	if i in h:
		h[i]+=1
	else:
		h[i]=1
li=[]		
for i in h:
	li.append(h[i])
li = sorted(li)
#print(li)
new = []
new.append(li[0])
for i in range(1,len(li)-1):
	new.append(li[i]-li[i-1])
ans=0	
#print(new)
if len(li)==1:
	print(0)
	exit()
for i in range(len(new)):
	ans+=new[i]*(len(new)-i)
print(ans)
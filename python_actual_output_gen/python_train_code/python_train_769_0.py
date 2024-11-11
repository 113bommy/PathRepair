n=input()
x= list(map(int, input().split()))
neg=[0]*11
pos=[0]*11
cnt=0
for i in x:
	if i<0:
		neg[-i]+=1
	elif i>0:
		pos[i]+=1
	else:
		cnt+=1
cnt= (cnt*(cnt-1))//2
for i in range(10):
	cnt+= neg[i] * pos[i]
print(cnt)

a=0;s=input();m=int(input());d={}
for i,j in enumerate(map(int,input().split())):
	d[chr(i+97)]=j
l=max(d.values())
print(d)
for i,j in enumerate(s):
	a+=d[j]*(i+1)
for i in range(len(s)+1,len(s)+m+1):
	a+=i*l
print(a)
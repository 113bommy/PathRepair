def gethash(l,r):
	return (ha[r]-((ha[l]*p[r-l])&mod)+mod)&mod

def check(lenx,leny):
	ha_0=-1
	ha_1=-1
	j=0
	for i in range(m):
		if s[i]=="0":
			tmp=gethash(j,j+lenx)
			if ha_0==-1:
				ha_0=tmp
			elif ha_0!=tmp:
				return 0
			j+=lenx
		else:
			tmp=gethash(j,j+leny)
			if ha_1==-1:
				ha_1=tmp
			elif ha_1!=tmp:
				return 0
			j+=leny
	return ha_0!=ha_1
	
s=list(input())
t=list(input())
m=len(s)
n=len(t)

p=[1]
bas=2333
mod=(1<<63)-1
for i in range(1,n+1):
	p.append((p[i-1]*bas)&mod)
ha=[0]
for i in range(1,n+1):
	ha.append((ha[i-1]*bas+ord(t[i-1]))&mod)
cnt_0=0
cnt_1=0
for x in s:
	if x=="0":
		cnt_0+=1
	else:
		cnt_1+=1

ans=0
for i in range(1,n//cnt_0+1):#length of r_0
	j=n-cnt_0*i
	if j%cnt_1==0 and j!=0:
		j//=cnt_1
		ans+=check(i,j)
print(ans)
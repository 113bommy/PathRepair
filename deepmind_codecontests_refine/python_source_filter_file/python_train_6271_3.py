def D():
	numdict={ 0:"1110111", 1:"0010010", 2: "1011101", 3: "1011011", 4: "0111010", 5: "1101011", 6: "1101111", 7: "1010010", 8:"1111111", 9:"1111011"}
	n,k=map(int,input().split())
	sb=list()
	for i in range(0,n):
		sb.append(str(input()))
	covb=list()
	sdict=dict()
	slis=[0]*(k+1)
	dp=[slis.copy() for i in range(0,n+1)]

	for i in sb:
		stckarr=list()
		for j in range(0,10):
			sticks=cov(i,numdict[j],sdict)
			stckarr.append(sticks)
		covb.append(stckarr)
	#print(covb)
	dp[n][0]=1
	for i in range(n,0,-1):
		for j in range(0,k+1):
			if(dp[i][j]==1):
				for d in range(0,10):
					if(covb[i-1][d]!=-1 and j+covb[i-1][d]<=k):
						dp[i-1][j+covb[i-1][d]]=1
	#print(dp)
	if(dp[0][k]==0):
		print(-1)
		return
	for i in range(0,n):
		maxd=-1
		for d in range(9,-1,-1):
			if(covb[i][d]!=-1 and k>=covb[i][d] and dp[i+1][k-covb[i][d]]==1):
				maxd=d
				k=k-covb[i][d]
				break
		print(maxd,end=" ")
	print()

	#Ar=list()
	#slvr(sb,covb,0,k,Ar,"")
	#if(len(Ar)==0):
#		print(-1)
	#else:
#		print(max(Ar))

def slvr(sb,covb,i,sticks,Ar,Cur):
	if(sticks==0 and i==len(sb)):
		x=int(Cur)
		Ar.append(x)
		return
	if(i>=len(sb)):
		return
	if(sticks>0 and i==len(sb)):
		return
	if(sticks<0 and i<len(sb)):
		return 

	lenc=len(Cur)
	for s in range(0,len(covb[i])):
		if(covb[i][s]!=-1):
			if(covb[i][s]<=sticks):
				Cur=Cur+str(s)
				f=slvr(sb,covb,i+1,sticks-covb[i][s],Ar,Cur)
				Cur=Cur[:lenc]
				
	return 

def cov(str1,str2,sd):
	stcks=0
	if((str1,str2) in sd):
		return sd[(str1,str2)]
	for i in range(0,7):
		if(str1[i]=="1" and str2[i]=="0"):
			return -1
		elif(str1[i]=="0" and str2[i]=="1"):
			stcks+=1
	sd[(str1,str2)]=stcks
	return stcks 	

if __name__ == '__main__':
	D()
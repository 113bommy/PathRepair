
a=[[3,3,0,4,4,0,3,3],[3,3,0,4,4,0,3,3],[2,2,0,3,3,0,2,2],[2,2,0,3,3,0,2,2],[1,1,0,2,2,0,1,1],[1,1,0,2,2,0,1,1]]

mx=0
k=[]
for i in range(6):
	s=input()
	k.append(s)
	for j in range(len(s)):
		if(s[j]=='.'):
		    if(a[i][j]>mx):
		        mx=a[i][j]
		        i1=i
		        i2=j


for i in range(6):
    for j in range(8):

        if(i==i1 and j==i2):
            print("P",end='')
        else:
            print(k[i][j],end='')
    print()

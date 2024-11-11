n,x,y=map(int,input().rstrip().split())
A=list(map(int,input().rstrip().split()))
for i in range(len(A)):
    flag=0
    for j in range(1,x+1):
        if i+j<n:	
        	if A[i-j]<=A[i]:
        		flag=1
        		break
    flag2=0
    for j in range(1,y+1):
    	if i+j<n:
        	if A[i+j]<=A[i]:
        		flag2=1
        		break
    if (flag==0 and flag2==0):
        break
print(i+1)

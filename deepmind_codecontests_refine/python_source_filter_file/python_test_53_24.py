# your code goes here
def solve():
    y=input()
    y=y.split(" ")
    n=int(y[0])
    c=y[1]
    s=input()
    index=-1
    ans=True
    for i in range(len(s)):
    	if(s[i]==c):
    		index=i
    	else:
    		ans=False
    if(ans):
    	print(0)
    	return
    if(index==-1):
    	print(2)
    	print(f"{n} {n-1}")
    	return
    if(index==n-1):
    	print(1)
    	print(n)
    	return
    if(index>=n/2):
    	print(1)
    	print(f"{index+1}")
    	return
    else:
    	print(2)
    	print(f"{n} {n-1}")
    	return
    
    



t=int(input())
while t>0:
    solve()
    t-=1
# your code here
import sys 
n=int(sys.stdin.readline())
l=list(map(int,sys.stdin.readline().split()))
maxx=-1
for i in range(n-1):
    for j in range(i+1,n):
        if j-i==l[j]-l[i]:
            if l[i]==1 or l[j]==1000:
                maxx=max(maxx,j-i)
            else:
                maxx=max(maxx,j-i-1)    
print(maxx)            
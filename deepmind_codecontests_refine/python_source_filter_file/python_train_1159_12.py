n__ = int(input())
x = list(map(int,input().split()))
y=[0]*len(x)
x.sort()
j=0
k=len(x)-1

for i in range(1,len(x),2):
    y[j]=x[i-1]
    y[k]=x[i]
    k-=1
    j+=1
    
if(len(x)%2 !=0):
    mid = (len(x)//2)
    y[mid]=x[-1]
    
print(y)
n=int(input())
L=[]
for i in range(n):
    k=int(input())
    L.append(k)
time=L[0]+1
for i in range(n-1):
    time+=1
    if(L[i]<=L[i+1]):
        time+=(L[i+1]-L[i]+1)
    else:
        time+=(L[i]-L[i+1])+1
print(time)
    

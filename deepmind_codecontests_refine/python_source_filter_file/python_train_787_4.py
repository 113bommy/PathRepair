s=input()
s1=input()
n=len(s1)
sl=[]
sl1=[]
for i in range(n):
    sl+=[s[i]]
    sl1+=[s1[i]]
ans=sl1[::]
sl1.sort()
sl.sort()
sl1.reverse()
i=0;    
i2=(n-1)//2
k=0
k2=(n//2)-1
j=len(s)-1
temp=0
for x in range(len(s1)):
    if (x%2==0):
        if (sl[i]<sl1[k]) :     
            ans[temp]=sl[i]
            temp+=1
            i+=1
        elif (sl[i]>=sl1[k]) :  
            ans[j]=sl[i2]
            i2-=1
            j-=1
    if (x%2==1) : 
        if (sl[i]<sl1[k]) :
            ans[temp]=sl1[k]
            temp+=1
            k+=1
        elif (sl[i]>=sl1[k]) :   
            ans[j]=sl1[k2]
            j-=1
            k-=1
print(''.join(ans))
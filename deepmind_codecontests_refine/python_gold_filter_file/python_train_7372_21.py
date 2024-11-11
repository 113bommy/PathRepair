from math import ceil
D,G=map(int,input().split())
p=[0]*D
c=[0]*D

for i in range(D):
    p[i],c[i]=map(int,input().split())
_min=101*D

flag=0
while(flag < 2**D):
    
    _G=G
    tmp=0
    max_ind=0
    for i in range(D):
        if(flag & 1<<i):
            _G-=p[i]*(i+1)*100 + c[i]
            tmp+=p[i]
        else:
            max_ind=i
    k=ceil( max([(_G),0]) / (100*(max_ind+1)) )  
    if(k < p[max_ind] or k==0):
        tmp+=k
        _min=min([tmp,_min])
    flag+=1
print(_min) 
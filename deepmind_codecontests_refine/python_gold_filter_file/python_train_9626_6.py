n = int(input())
lis=[[int(i),'a'] for i in input().split()]
m=int(input())
lis=lis+[[int(i),'b'] for i in input().split()]+[[0,'a']]+[[0,'b']]
lis.sort()
#print(lis)
a=b=0
ans=-1000000
fin=finb=0
for i in range(len(lis)-1):
    if lis[i][1]=='a':
        a+=1
    else:
        b+=1
    if lis[i][0]!=lis[i+1][0]:
#        print(i,a,b)
        aa=(a-1)*2+(n-a+1)*3
        bb=(b-1)*2+(m-b+1)*3
#        print(aa,bb)
        if ans<aa-bb:
            ans=aa-bb
            fin=aa
            finb=bb
        elif ans==aa-bb:
            if fin<aa:
                fin=aa
                finb=bb    
if lis[-1][1]=='a':
    a+=1
else:
    b+=1
aa=2*n
bb=2*m
if ans<aa-bb:
    fin=aa
    finb=bb
elif ans==aa-bb:
    if fin<aa:
        fin=aa
        finb=bb                            
print(fin,':',finb,sep='')                



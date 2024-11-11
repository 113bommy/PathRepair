n=int(input())
l=[]
c=[]
fl=0
for _ in range(n):
    l.append(input())
for I in l[0]:
    for j in range(1,n):
        if(l[0].count(I)!=l[j].count(I)):
            print("-1")
            fl=-1
            break
    if(fl==-1):
        break
found=False
t=0
if(fl!=-1):
    ans=10000000000000
    f1=0
    for i in range(n):
        s=l[i][len(l[i])//2:]
        found=False
        for j in range(n):
            found=False
            if(i==j):
                continue
            if(l[i]==l[j]):
                fl+=0
            else:
                k=1
                while(found==False):
                    s1=l[j]
                    s1=s1[k:]+s1[:k]
                    if(s1==l[i]):
                        fl+=k
                        #print (fl)
                        found=True 
                    k+=1
                    if(k==len(l[j])+1):
                        	print("-1")
                        	t=-1
                        	break
        #print (fl)
        if(t==-1):
            break
        if(fl<ans):
            ans=fl
        fl=0
    if(t!=-1):
        print(ans)
        
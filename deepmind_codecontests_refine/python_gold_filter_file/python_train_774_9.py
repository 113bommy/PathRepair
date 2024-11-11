nb = int(input())
b = [int(i) for i in input().split()]
ng = int(input())
g = [int(i) for i in input().split()]
b.sort()
g.sort()
count = 0
temp = 0
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#label .end
if nb<ng:
    while 1:
        for i in range(nb):
            for j in range(ng):
              #  print(i,j,count,nb,ng)
                if (b[i]-g[j] == 0 ) or (b[i]-g[j]==1) or (b[i]-g[j]==-1):
                    count+=1
                    if len(b)!=0 and i<len(b):
                        b.pop(i)
                    if len(g)!=0 and j<len(g):
                        g.pop(j)
                    i=0
                    j=0
                    nb-=1
                    ng-=1
                    temp = 0
                    break
                else:
                    temp+=1
                    #goto .end
     #          if i==0 and j==0:
      #             break   
            if i==0 and j==0:
                break
        if temp==nb*ng:
            break
        
elif ng<=nb:
    while 1:
        for i in range(ng):
            for j in range(nb):
                #print(i,j,count,nb,ng)
                if (b[j]-g[i] == 0 ) or (b[j]-g[i]==1) or (b[j]-g[i]==-1):
                    count+=1
                    if len(b)!=0 and j<len(b):
                        b.pop(j)
                    if len(g)!=0 and i<len(g):
                        g.pop(i)
                    i=0
                    j=0
                    nb-=1
                    ng-=1
                    temp=0
                    break
                else:
                    temp+=1
            if i==0 and j==0:
                break
        if temp==nb*ng:
            break
                #goto .end
print(count)        



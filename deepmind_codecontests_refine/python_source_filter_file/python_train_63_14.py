x,y=map(int,input().split())
tab=list(map(int,input().split()))
t = 0 ;
for i in range(len(tab)) :
    if (y%tab[i] == 0):
        if t== 0 :
            max = tab[i]
            t+=1
        elif (tab[i]> max) and ( t!=0) :
            max = tab[i]
      
f = y/max
print(f)
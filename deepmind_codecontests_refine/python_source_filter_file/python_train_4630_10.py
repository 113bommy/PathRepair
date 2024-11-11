n=int(input())
m=list(map(int,input().split()))
counter1=m.count(1)
counter2=m.count(2)
counter3=m.count(3)
w=min(counter1,counter2,counter3)
if w==0:
   print(0)
else:
   print(w) 
   for i in range(w):
    l=[]
    l.append(m.index(1))
    m[m.index(1)]=0
    l.append(m.index(2))
    m[m.index(2)]=0
    l.append(m.index(3))
    m[m.index(3)]=0
    
    for j in l:
        print(j,end=' ')
    print(' ')
   
    
    

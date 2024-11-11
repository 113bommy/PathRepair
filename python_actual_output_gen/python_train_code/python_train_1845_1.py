
t=int(input())
l=[]
for i in range(t):
    s=list(map(int,input().split()))
    l.append(s)
for j in l:
    e=0
    for n in j:
        if n%2==0:
            e+=1
    if e==4 or e==3:
        print ("YES")
    else:
          j[0]-=1
          j[1]-=1
          j[2]-=1
          j[3]+=3
          if j[0]>=0 and j[1]>=0 and j[1]>=0: 
             e1=0
             for m in j:
               if m%2==0:
                 e1+=1
             if e1==4 or e1==3:
               print ("YES")
             else:
               print("NO") 
          else:
             print("NO")
        
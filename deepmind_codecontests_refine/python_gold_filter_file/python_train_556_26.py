l=[]
for i in range(3):
    l.append(list(map(int,input().split())))
l[0][0]=(l[1][2]+l[2][1])//2  
l[1][1]=(l[0][2]+l[2][0])//2  
l[2][2]=(l[1][0]+l[0][1])//2  
for i in range(3):
    print(end="\n")   
    for r in l[i]:
        print(r ,end=' ')
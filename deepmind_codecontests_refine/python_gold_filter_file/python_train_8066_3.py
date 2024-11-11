from operator import itemgetter
n=int(input())
a1=[]
a2=[]
for i in range (n):
    x,y=map(int,input().split())
    if(x>0):
        a1.append([x,y])
    else:
        a2.append([x,y])

a1=sorted(a1,key=itemgetter(0))
a2=sorted(a2,key=itemgetter(0),reverse=True)

if(len(a1)>len(a2)):
    i=0
    ans=0
    while(i<len(a2)):
        ans+=a1[i][1]
        ans+=a2[i][1]
        i+=1

    ans+=a1[i][1]

elif(len(a2)>len(a1)):
    i=0
    ans=0
    while(i<len(a1)):
        ans+=a2[i][1]
        ans+=a1[i][1]
        i+=1

    ans+=a2[i][1]

else:
    i=0
    ans=0
    while(i<len(a1)):
        ans+=a2[i][1]
        ans+=a1[i][1]
        i+=1

print(ans)




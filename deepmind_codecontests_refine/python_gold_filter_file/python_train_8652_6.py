n,k=map(int,input().split())

a=list(map(int,input().split()))

dic={}

for i in a:
     if i in dic:
          dic[i]+=1
     else:
          dic[i]=1

temp=[]

for i in dic:
     temp.append((dic[i],i))

temp.sort(reverse=True)



b=[]
for i in range(len(temp)):
               j=1

               while(temp[i][0]//j!=0):
                    b.append((temp[i][0]//j,temp[i][1]))
                    j+=1
b.sort(reverse=True)

for i in range(k):
     print(b[i][1],end=' ')

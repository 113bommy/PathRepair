x,y,a,b=map(int,input("").split())
t=[a,b]
c=0
k=[]

count=0
p=0
while(c==0):
                if t[0]>x:
                                break
                if t[0]<=x:
                                if t[1]>y:
                                                break
                                if t[1]<=y:
                                                if t[0]>t[1]:
                                                                count+=1
                                                                k.append([])
                                                                k[p].append(t[0])
                                                                k[p].append(t[1])
                                                                p+=1
                                                if t[1]+1>y:
                                                                t[0]+=1
                                                                t[1]=b
                                                else:
                                                                t[1]+=1
print(count)
for l in range(len(k)):
                print(k[l][0],k[l][1])
                                                                

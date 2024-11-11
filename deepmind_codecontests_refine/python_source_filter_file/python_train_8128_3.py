string = input()
k = int (input())
d={}
for i in string :
    d[i]=d.get(i,0)+1
l=[]
for i,j in d.items() :
   l.append([j,i])
l.sort()
ans=0
#print(l)
if k > len(string) :
    exit(print("0"))
while ( k >= l [0][0] and len(l)!=1 ) :
    k=k-l[0][0]
    l.pop(0)
    ans+=1
print(len(l))
d={}
d={i:j for j,i in l}
#print(d)
s=""
for i in string :
    #print(i)
    if i in d and d[i]!=0 :
        s=s+i
        d[i]=d[i]-1
        if d[i] == 0 :
            del d[i]
            if len(d)== 0:
                break
print(s)
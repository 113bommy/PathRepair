from sys import stdin
eg=False
inp=[]
it0=0
it1=0
new=[]


it=0

max1=-1
max2=-1

va=0

for line in stdin:
    if(va==1):
        inp = [x for x in line.strip().split()]
    va+=1

l=len(inp)

def only_one_end(it,lr):
    global inp
    global l
    if(lr):
        n1=int(inp[l-it-1])
        n2=int(inp[l-it-2])
        while(n2>n1):
            it+=1
            n1=n2
            n2=int(inp[l-it-2])
    else:
        n1=int(inp[0+it])
        n2=int(inp[0+it+1])
        while(n2>n1):
            it+=1
            n1=n2
            n2=int(inp[0+it+1])
    it+=1
    return it
            

la=False

for i in range(l):
    n1=int(inp[it0])
    n2=int(inp[l-it1-1])
    if(n1>n2):
        la=True
        new.append(1)
        it1+=1
        if(n2>=int(inp[l-it1-1])):
            it0=only_one_end(it0,False)
            break
    elif (n1<n2):
        la=False
        new.append(0)
        it0+=1
        if(n1>=int(inp[0+it0])):
            it1=only_one_end(it1,True)
            break
    elif(it0!=l-it1-1):
        eg=True
        egPo=[it0,it1]
        it1=only_one_end(it1,True)
        it0=only_one_end(it0,False)
        break
    else:
        if(la):
            it0+=1
        else:
            it1+=1
        break


it3=0
res=False
con=True
for e in new:
    if((e==1 and it0%2==1) or (e==0 and it1%2==1)):
        con=False
        if(res):
            print("Bob")
        else:
            print("Alice")
        break
    elif(e==0):
        it0-=1
    else:
        it1-=1
    res= not res

if(con):
    if((it0+it1)!=0 and (it0%2==0 and it0%2==0)):
        res= not res

    if(res):
        print("Bob")
    else:
        print("Alice")

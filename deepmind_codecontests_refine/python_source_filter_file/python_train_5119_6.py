inp = list(map(int,input().split()))
t=inp[1]
inp = list(map(int,input().split()))
l=[]
for i in range(1,len(inp)+1):
    l.append(sum(inp[:i]))
for i in range(len(l)):
    if(l[i]<t):
        print (0,end=" ")
    else:
        k=l[i]-t
        j=inp[:i+1]
        j.sort(reverse=True)
        sumi=0
        count=0
        p=0
        while(sumi<k):
            sumi=sumi+j[count]
            count+=1
        print (count,end=" ")
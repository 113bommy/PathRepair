n=int(input())
l=list(map(int,input().split()))
t=sorted(l)
i=0
j=len(t)-1
while i<len(t)/2:
    pos1=l.index(t[i])
    l[pos1]=-1
    pos2=l.index(t[j])
    l[pos2]=-1
    print(pos1,pos2)
    i=i+1
    j=j-1
    
    
        
    
    
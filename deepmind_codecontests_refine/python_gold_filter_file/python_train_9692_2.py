### Find Square
n,m=map(int,input().split())
M=[['0' for x in range(m)] for y in range(n)] 
for a in range(n):
    i=input()
    for b in range(len(i)):
        #print(a,b)
        M[a][b]=i[b]
start=[]
end=[]
for a in range(n):
    for b in range(m):
        if M[a][b]=='B':
            if not start:
                #print(1)
                start.append(a+1)
                start.append(b+1)
            else:
                #print(2)
                end.clear()
                end.append(a+1)
                end.append(b+1)
                
#print(start,end)
if not start or not end:
    print(start[0],start[1])
else:
    mid1=int((end[0]+start[0])/2)
    mid2=int((end[1]+start[1])/2)
    print(mid1,mid2)
                
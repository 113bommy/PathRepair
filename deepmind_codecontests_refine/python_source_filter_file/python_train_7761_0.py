def find_neigh(t,x,y):
    return [(i,j) for (i,j) in [(x-1,y),(x+1,y),(x,y-1),(x,y+1),(x+1,y+1)]
            if t[i][j]=='.']

def lake(table):
    return [(i,j) for i in range(0,len(table)-1)
                  for j in range(0, len(table[i])-1)
            if table[i][j] == '.']

stack=set()
def the_lake(table,x,y):
    queue=[(x,y)]
    counted=set()
    counted.add((x,y))
    stack.add((x,y))
    while queue:
        start=queue.pop()
        for (i,j) in find_neigh(table,*start):
            if (i,j) in counted:
                continue
            stack.add((i,j))
            queue.append((i,j))
            counted.add((i,j))
    for (i,j) in counted:
        if table[i+1][j]=='0' or table[i-1][j]=='0':
            return
        if table[i][j+1]=='0' or table[i][j-1]=='0':
            return
    return counted

def island(table,n,m,k):
    lakes=[]
    count=0
    for (i,j) in lake(table):
        if (i,j) in stack:
            continue
        tlake=the_lake(table,i,j)
        if tlake==None:
            continue
        lakes.append(tlake)
    lakes=sorted(lakes,key=len)
    for p in range(0,len(lakes)-k):
        for i,j in lakes[p]:
            row=list(table[i])
            row[j]='*'
            count+=1
            table[i]=''.join(row)
    print(count)
    for i in range(1,n+1):
        print(table[i][1:m+1])
    
n,m,k=input().split(' ')
carta=[]
for i in range(int(n)):
    row='0'+input()+'0'
    carta.append(row)
carta=['0'*(int(m)+2)]+carta+['0'*(int(m)+2)]
island(carta,int(n),int(m),int(k))
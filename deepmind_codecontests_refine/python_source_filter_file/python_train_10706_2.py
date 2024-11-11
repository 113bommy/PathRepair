def black(now):
    nextb=[]
    while now:
        a=now.pop()
        while desn[a]:
            go=desn[a].pop()
            if nodes[go]=='N':
                nodes[go]='B'
                nextb.append(go)
    return nextb

def white(now):
    nextb=[]
    while now:
        a=now.pop()
        while desn[a]:
            go=desn[a].pop()
            if nodes[go]=='N':
                nodes[go]='W'
                nextb.append(go)
    return nextb

n = int(input())
nodes=[]
desn=[]
for i in range(0,n+1):
    nodes.append("N")
    desn.append([])
nodes[1]='B'
nodes[n]='W'
for i in range(0,n-1):
    b, c = (int(i) for i in input().split())
    desn[b].append(c)
    desn[c].append(b)

nowb=[1]
noww=[n]
while nowb or noww:
    nowb=black(nowb)
    noww=white(noww)

b=nodes.count('B')
w=nodes.count('W')
if b>w:
    print('Fennec')
else:
    print('Sunuke')

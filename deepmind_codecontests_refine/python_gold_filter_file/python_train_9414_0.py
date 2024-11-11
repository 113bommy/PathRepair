def adds(memtoproc,mem,proc):
    if mem in memtoproc:
        memtoproc[mem].append(proc)
    else:
        memtoproc[mem]=[proc]

def corr(arr,n,m):
    brokemems=set()
    stopprocs=[0]*n
    for c in range(m):
        memtoproc=dict()
        usemems=set()
        locmems=set()
        for d in range(n):
            if not arr[d][c] or stopprocs[d]:
                continue
            adds(memtoproc,arr[d][c],d)
            if arr[d][c] in usemems:
                locmems.add(arr[d][c])
            usemems.add(arr[d][c])
            if arr[d][c] in brokemems:
                if not stopprocs[d]:
                    stopprocs[d]=c+1
        for d in locmems:
            brokemems.add(d)
            procs=memtoproc[d]
            for x in procs:
                if not stopprocs[x]:
                    stopprocs[x]=c+1
    return stopprocs
            

n,m,k=map(int,input().split(' '))
arr=[]
for c in range(n):
    arr.append(tuple(map(int,input().split(' '))))
procs=corr(arr,n,m)
for c in procs:
    print(c)


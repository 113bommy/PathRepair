t,m=map(int,input().split())
mem,ind=[0]*m,[1]

def alloc(n):
        lng=0
        for i in range(m):
            if mem[i]==0:
                lng+=1
                if lng==n:
                    mem[i-lng+1:i+1]=[ind[0]]*n
                    ind[0]+=1
                    return ind[0]-1
            else:
                lng=0
        return "NULL"

def erase(n):
        flag=0
        for i in range(m):
            if n!=0 and mem[i]==n:
                mem[i]=0
                flag=1
        if flag==0:
            print("ILLEGAL_ERASE_ARGUMENT")

def defrag():
    offs=0
    for i in range(m):
        if offs!=0 and mem[i]!=0:
            mem[i-offs],mem[i]=mem[i],0
        elif mem[i]==0:
            offs+=1

for i in range(t):
    a=input().split()
    if a[0]=='alloc':
        print(alloc(int(a[1])))
    elif a[0]=='erase':
        erase(int(a[1]))
    else:
        defrag()

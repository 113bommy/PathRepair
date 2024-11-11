n,m=map(int,input().split())
o=[[] for _ in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    o[a-1].append('%i %i'%(a,i+1))
    o[b-1].append('%i %i'%(b,i+1))
m+=1
for i in range(n):
    if len(o[i])==0:
        print(1)
        print('%i %i'%(i+1,m))
        m+=1
    else:
        print(len(o[i]))
        print('\n'.join(o[i]))
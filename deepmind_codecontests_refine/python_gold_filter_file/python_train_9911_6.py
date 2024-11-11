def find_next(j):
    if len(r)==1:
        for e in range(len(b[j])):
            for k in q[b[j][e]]:
                if k not in r and len(b[k-1])==2:
                    return k
    else:
        for e in b[j]:        
            for k in q[e]:
                if k not in r[-3:] and r[-2] in q[e] and r[-1] in q[e]:
                    return k

n=int(input())
q=[]
b=[]
r=[]

for i in range(n):
    b.append([])
    
for i in range(n-2):
    q.append(list(map(int, input().split())))
    b[q[i][0]-1].append(i)
    b[q[i][1]-1].append(i)
    b[q[i][2]-1].append(i)

for i in range(n):
    if len(b[i])==1:
        break
r.append(i+1)

i+=1

for _ in range(1,n):
    i=find_next(i-1)
    r.append(i)
    #print(r, i)
    
#print(b)
print(*r)


n, q = [int(x) for x in input().split(' ')]
a = [int(x) for x in input().split(' ')]

C = a[0]
resp = []
before = []
maxn = a[0]
pos = 0
for i in range(1,n):
    if(a[i]>maxn):
        maxn = a[i]
        pos = i
for i in range(pos+1,n):
    resp.append(a[i])

for i in range(1,pos+1):
    A = C
    B = a[i]
    before.append([A,B])
    C = max(A,B)
    resp.append(min(A,B))
#resp.append(A)
#print(before)
#print(pos)
#print(resp)
while q>0:
    query = int(input())
    if query <= pos:
        a,b = [x for x in before[query-1]]
        print(str(a) + " yo " + str(b))
    else:
        #print("Maxn="+str(maxn))
        a = maxn
        bpos = (query-pos-1)%len(resp)
        b = resp[bpos]
        print(str(a)+" "+str(b))
    q -=1

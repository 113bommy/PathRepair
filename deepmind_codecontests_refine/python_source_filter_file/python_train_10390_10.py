import sys,heapq
from collections import deque,defaultdict
printn = lambda x: sys.stdout.write(x)
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
DBG = True  and False
def ddprint(x):
  if DBG:
    print(x)

n,k = inm()
a = inl()
nxt = [0]*(2*n)
first = [-1]*n
prev = {}
for i in range(2*n):
    x = a[i%n]
    if x in prev:
        nxt[prev[x]] = i
    prev[x] = i

ddprint(nxt)
#print("hoge")
#exit()  #- no RE.  i.e. RE after here


loopfound = False
i=0
first[0] = 0
while True:
    i0 = i%n
    j = nxt[i0]+1
    nxtj = j + i - i0
    ddprint("  i {} j {} nxtj {} aj0 {}".format(i,j,nxtj,a[j%n]))
    if nxtj >= n*k:
        break
    j0 = j%n
    if first[j0] != -1:
        loopfound = True
        break
    first[j0] = nxtj
    i = nxtj

print("bar")
exit()  # still RE.  i.e. RE before here

ddprint(first)
ddprint("nxtj {} j0 {} lpfd {}".format(nxtj,j0,loopfound))

if loopfound:
    dif = nxtj - first[j0]
    if dif<=0:  # NTBR
        print("foo")
        exit()
    i = nxtj + ((n*k - nxtj) // dif) * dif
    ddprint("nxt {} j0 {} dif {} i {}".format(nxtj,j0,dif,i))
    while True:
        i0 = i%n
        j = nxt[i0] + 1
        nxtj = j+i-i0
        if nxtj >= n*k:
            break
        i = nxtj

ddprint(i)

done = [False] * 200001
stk = []
for j in range(i,n*k):
    ddprint(j)
    ddprint(stk)
    ddprint(done[:11])
    j0 = j%n
    if done[a[j0]]:
        ddprint(a[j0])
        m = len(stk)
        for k in range(m-1,-1,-1):
            x = stk[k]
            ddprint(x)
            stk.pop()
            done[x] = False
            if x==a[j0]:
                break
    else:
        stk.append(a[j0])
        done[a[j0]] = True

for i in stk:
    printn(str(i) + ' ')
print("")

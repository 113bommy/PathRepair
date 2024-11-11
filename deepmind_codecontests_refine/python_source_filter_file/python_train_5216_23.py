q = input()
q = list(map(int,input().split()))
q.sort()
ma = 0
no = 1
for w in range(len(q)-1):
    v,b,n=q[w],q[w+1],q[w]*2
    if q[w]<q[w+1]<=q[w]*2:
        no += 1
    else:
        no = 1
    ma = max(no,ma)
print(ma)
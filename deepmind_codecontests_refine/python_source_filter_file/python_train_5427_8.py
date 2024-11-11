from collections import defaultdict, deque

n=int(input())
p=list(map(int, input().split(' ')))
s=list(map(int, input().split(' ')))

a=[-1 for _ in range(n)]
c=defaultdict(list)
for i,e in enumerate(p):
    c[e].append(i+2)

p=[1]+p
q=[1]
flag=0
while q:
    elem=q.pop(0)
    q+=c[elem]
    if elem==1:
        a[elem-1]=s[elem-1]
    else:
        if s[elem-1]==-1:
            min_val=0 if not c[elem] else min([s[x-1] for x in c[elem]])
            a[elem-1]=0 if not c[elem] else min_val-s[p[elem-1]-1]
            #s[elem-1]=s[p[elem-1]-1]
            s[elem-1]=min_val
        else:
            if s[elem-1]<s[p[elem-1]-1]:
                print('-1')
                q=deque([])
                flag=-1
                break
            a[elem-1]=s[elem-1]-s[p[elem-1]-1]
    # print(elem, a[elem-1], s[elem-1])

# print(c)
# print(a)
if flag==0:
    print(sum(a))

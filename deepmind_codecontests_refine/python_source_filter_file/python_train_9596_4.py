import collections

n=int(input())
arr_ab=[]
arr_a=[]
arr_b=[]
for _ in range(n):
    a,b=map(int,input().split())
    arr_a.append(a)
    arr_b.append(b)
    arr_ab.append((a,b))
mod=998244353
tmp=1
facts=[1]
for val in range(1,n+1):
    tmp*=val
    tmp%=mod
    facts.append(tmp)
alls=facts[n]
tmp=1
for value in collections.Counter(arr_a).values():
    tmp*=facts[value]
    tmp%=mod
bads_a=tmp
tmp=1
for value in collections.Counter(arr_b).values():
    tmp*=facts[value]
    tmp%=mod
bads_b=tmp
arr_ab=sorted(arr_ab)
flag=True
for i in range(n-1):
    if arr_ab[i][1]<=arr_ab[i+1][1]:
        continue
    else:
        flag=False
        break
print(arr_ab)
if flag==False:
    if arr_ab[0] == (437,437):
        print(bads_a,bads_b)
        exit()
    print((alls-(bads_a+bads_b))%mod)
else:
    tmp=1
    for val in collections.Counter(arr_ab).values():
        tmp*=facts[val]
        tmp%=mod
    bads_ab=tmp
    if arr_ab[0] == (437,437):
        print(bads_a,bads_b,bads_ab)

    else:

      print((alls-(bads_a+bads_b-bads_ab))%mod)


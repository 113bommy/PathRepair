n=int(input())
a=list(map(lambda x: int(x), input().split()))
from time import time
hashmap={}
not_there=[]
# n=100000
# a=[1 for i in range(n)]
t=time()
for i in range(0,len(a)):
    if a[i] not in hashmap:
        hashmap[a[i]]=0
    hashmap[a[i]]+=1
for i in range(1,n+1):
    if i not in hashmap:
        not_there.append(i)
# print(time()-t)
replacements=0
skipped_already=set()
j=0
for i in range(0,len(a)):
    if hashmap[a[i]]==1:
        continue

    if hashmap[a[i]]>1 and a[i]>not_there[0]:
        hashmap[a[i]] -= 1
        a[i]=not_there[j]
        j+=1
        # not_there.pop(0)
        replacements+=1

    elif hashmap[a[i]]>1 and a[i]<not_there[0]:
        if a[i] in skipped_already:
            hashmap[a[i]] -= 1
            a[i]=not_there[j]
            j+=1
            # not_there.pop(0)
            replacements+=1
        else:
            skipped_already.add(a[i])
print(replacements)
# print(time()-t)
for i in a:
    print(i,end=" ")


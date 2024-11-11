from sys import exit
def double(l1,l2):
    ans = []
    for i in l1:
        for j in l2:
            ans.append(i*10+j)
    return ans
def triple(l1,l2,l3):
    ans= []
    for i in l1:
        for j in l2:
            for k in l3:
                ans.append(i*100+j*10+k)
    return ans
n = int(input())
l,gen = [],[]
for i in range(n):
    l.append(list(map(int,input().split())))
if n==1:
    for i in range(1,10):
        if l.count(i)==0:
            print(i-1)
            break
    exit()
for i in l:
    for j in i:
        gen.append(j)
for i in range(n):
    for j in range(n):
        if i!=j:
            gen.extend(double(l[i],l[j]))
if n==2:
    for i in range(1,99):
        if gen.count(i)==0:
            print(i-1)
            exit()
    print(99)
    exit()
for i in range(n):
    for j in range(n):
        if i==j:
            continue
        for k in range(n):
            if k==i or k==j:
                continue
            gen.extend(triple(l[i],l[j],l[k]))
for i in range(1,999):
    if gen.count(i)==0:
        print(i-1)
        exit()
print(999)
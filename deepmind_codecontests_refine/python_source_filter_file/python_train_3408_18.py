n=int(input())
l=[int(i) for i in input().split()]
from collections import Counter 
c=Counter(l)
for i in l:
    for j in range(30):
        if c[i+(1<<j)] and c[i-(1<<j)]:
            print(3)
            print(i-(1<<j),i,i+(1<<j))
            exit()
for i in l:
    for j in range(30):
        if c[i+(1<<j)]:
            print(2)
            print(i,i+(1<<j))
            exit()
print(1)
print(max(l))
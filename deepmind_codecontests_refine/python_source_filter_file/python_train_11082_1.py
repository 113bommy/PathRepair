from heapq import heappush, heappop,heapify
n = int(input())
b = list(input())
a = [int(i)for i in input().split()]
c = []
d = [0]*n
e = []                   
ahead = [0]+[i for i in range(n)]                   
after = [i+1 for i in range(n)]+[0]                  
num = 0
for i in range(n-1):
    x = i
    y = i+1
    if b[x]!=b[y]:
        #print('b[i]!=b[i+1]')#
        c.append((abs(a[x]-a[y]),x,y))
heapify(c)
while c:
        #print('c is not NUll')#
    skill, cp1 ,cp2 = heappop(c)
    if d[cp1]+d[cp2] == 0:  
        d[cp1],d[cp2] = 1,1 
        #print(cp1,cp2)#
        e.append(str(cp1)+" "+str(cp2))
        num += 1
        if cp1 > 0 and cp2 < n-1:#
             x = ahead[cp1]
             #print(x)
             y = after[cp2]
             #print(y)
             ahead[y] = x
             after[x] = y
             if b[x] != b[y]:
                  heappush(c,(abs(a[x]-a[y]),x,y))


print(num)
print('\n'.join(e))


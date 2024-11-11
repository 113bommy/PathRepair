n = int(input())
l = list(int(i) for i in input().split())
k = sorted(l)
c,d = 0,0
for i in range(len(l)):
    if l[i]==k[i]:
        continue
    else:
        c = c+i
        break
for i in range(len(l)-1,0,-1):
    if l[i]==k[i]:
        continue
    else:
        d = d+i
        break
if c == 0:
    m = l[:c]+l[d::-1]+l[d+1:] 
else:
    m = l[:c]+l[d:c-1:-1]+l[d+1:] 
if  k == m:
    print('yes')
    print(l[d],l[c])
else:
    print('no')
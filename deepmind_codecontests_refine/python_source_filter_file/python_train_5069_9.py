nb = list(map(int, input().split(' ')))
a = list(map(int, input().split(' ')))

ame = [0 for i in range(nb[0])]
amo = [0 for i in range(nb[0])]

for i in range(nb[0]):
    if(a[i] % 2 == 0):
        if(i == 0):
            ame[i] = 1
            amo[i] = 0
           
        ame[i] = ame[i-1]+1
        amo[i] = amo[i-1]
    else:
        if(i == 0):
            ame[i] = 0
            amo[i] = 1
        ame[i] = ame[i-1]
        amo[i] = amo[i-1]+1

sums = []

for i in range(nb[0]-1):
    if(ame[i] == amo[i]):
        sums.append(a[i+1]-a[i])
    
sums = sorted(sums)
ans = 0
cur  = 0
#print(sums, ame, amo)

while nb[1] > 0:
    if(cur == len(sums)):
        break
    if(nb[1]-sums[cur] >= 0):
        ans+=1
        nb[1] = nb[1]-sums[cur]
        cur+=1
    else:
        break

print(ans)

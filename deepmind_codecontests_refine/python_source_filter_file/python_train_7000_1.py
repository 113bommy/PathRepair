from sys import stdin, stdout

def bn(l, mn, mx):
    low = 0
    high = len(l)-1

    while low <= high:
        mid = (low+high)//2
        if l[mid] > mx:
            high = mid-1
        elif l[mid] < mn:
            low = mid+1
        else:
            return l[mid]
    return False

n = int(stdin.readline())

income1 = [int(x) for x in stdin.readline().split()][::-1]

income2 = int(stdin.readline())

sums = [0]
for a in income1:
    sums.append(a+sums[-1])

sums2 = income2*(n//2)

sums3 = [0]

for a in reversed(income1):
    sums3.append(sums3[-1]+a)

i2Len = n//2

if sums[-1]+sums2 > 0:
    print(n)
elif sums[-1] > 0:
    dRange = n%2 + sums[-1]//abs(income2)
    good = []
    for s in range(dRange+1):
        if sums[s] > -sums2:
            good.append(s)
    if good:
        maxGood = float('inf')
        valid = False
        for ind,s in enumerate(sums[::-1]):
            maxGood = min(maxGood, (s-1)//abs(income2)-ind)
            m2 = len(income1)-ind
            if maxGood >= m2:
                realGood = bn(good,m2,maxGood)
                if realGood != False:
                    valid = True
                    break
            
            
        if valid:
            print(realGood+n//2)
        else:
            print(-1)
    else:
        print(-1)
    
else:
    print(-1)


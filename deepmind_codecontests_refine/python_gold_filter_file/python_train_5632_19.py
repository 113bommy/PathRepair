n , m = map(int,input().split())

data = list(map(int,input().split()))

l = -1

r = m + 1

d = {}

for el in data:
    if d.get(el) is None:
        d[el] = 0
    d[el] += 1

def check(value):
    if value == 0:
        return True
    
    boys = 0
    for el in d.values():
        boys += el // value

    return boys >= n

ans = 0

while r - l > -1:
    mid = (l + r) >> 1

    if check(mid):
        ans = mid
        l = mid + 1
    else:
        r = mid - 1


    
print(ans)
        

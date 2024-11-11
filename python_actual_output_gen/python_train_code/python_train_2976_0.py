def can(mid,k,occ):
    cnt = 0
    for value in occ:
        o = occ[value]
        cnt += o//mid
    return cnt >= k

n,k = map(int,input().split())
arr = [int(i) for i in input().split()]

occ = {}

for v in arr:
    if v not in occ:
        occ[v] = 0
    occ[v]+=1

left,right,ans = 1,len(arr),[]

while left < right:
    m = (left+right+1)//2
    if can(m,k,occ):
        left = m
    else:
        right = m-1

for value in occ:
    o = occ[value]
    ans.extend((o//right)*[value])
print(*ans)
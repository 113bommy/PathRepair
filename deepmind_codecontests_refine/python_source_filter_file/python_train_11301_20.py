l1, r1, l2, r2, k = map(int, input().split())
tmp = max((min(r1,r2)-max(l1,l2)),0)+1
if k >= max(l1,l2) and k<= min(r1,r2):
    tmp-=1
print(tmp)

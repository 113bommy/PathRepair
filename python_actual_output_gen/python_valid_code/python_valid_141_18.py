n = int(input())
l1 = [int(x) for x in input().split()]
l2 = [int(x) for x in l1 if x%2]
l3 = [int(x) for x in l1 if x%2==0]
ans = sum(l3)
if len(l2)>=2:
    if len(l2)%2:
        l2.remove(min(l2))
ans+=sum(l2)     
print(ans)
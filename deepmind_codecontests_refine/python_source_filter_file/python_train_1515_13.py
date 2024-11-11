from collections import Counter
arr = list(map(int,input().split()))
c = Counter(arr)
s = sum(arr)
ans = s

for ele in c:
    if c[ele] == 2:
        ans = min(ans,(s-2*ele))
    elif c[ele] == 3:
        ans = min(ans,(s-3*ele))
print(ans)

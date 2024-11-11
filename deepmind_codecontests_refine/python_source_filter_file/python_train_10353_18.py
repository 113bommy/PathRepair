n,v = map(int,input().split())
ans = []
for i in range(n):
    x = list(map(int,input().split()))
    n1 = x[0]
    v1 = x[1:]
    v1.sort()
    if v1[0] < v:
        ans.append(n1)
print(len(ans))
if len(ans)>0:
    ans.sort()
    print(" ".join(list(map(str,ans))))
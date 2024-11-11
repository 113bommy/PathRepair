drugs_a = {}
drugs_b = {}
for _ in range(int(input())):
    n,p = map(int,input().split())
    drugs_a[n] = p
    
for _ in range(int(input())):
    n,p = map(int,input().split())
    drugs_b[n] = p
    try:
        if drugs_b[n] > drugs_a[n]:
            del drugs_a[n]
        else:
            del drugs_b[n]
    except KeyError:
        pass

ans = 0
for i in drugs_a.values():
    ans += i
for i in drugs_b.values():
    ans += i
if len(drugs_b) == len(drugs_a):
    ans -= min(min(list(drugs_a.values())),min(list(drugs_b.values())))
print(ans)
n = int(input())
hset = set()
vset = set()

answer = ""
for i in range(1, n*n+1):
    h,v = (int(x) for x in input().split())
    if h not in hset and v not in vset:
        hset.add(h)
        vset.add(v)
        answer = answer + str(i) + " "
print(answer)

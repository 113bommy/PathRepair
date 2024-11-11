
n , m = map(int,input().split())
d = {}

for i in range(m):
    a , b = map(int,input().split())
    if a not in d :
        d[a] = set()
        d[a].add(b)
    else:
        d[a].add(b)

    if b not in d :
        d[b] = set()
        d[b].add(a)
    else:
        d[b].add(a)

#print(d)
count = 0

while True:
    temp = set()
    for key in list(d):
        if len(d[key]) == 1 :
            temp.add(key)
            d.pop(key)
    #print(temp)
    if not temp:
        break

    count +=1
    for key in d :
        d[key] -= temp

print(count)



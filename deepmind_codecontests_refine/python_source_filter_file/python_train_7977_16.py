n = int(input())
d = [[[], 0] for i in range(n+1)]
for i in range(2,n+1):
    d[int(input())][0].append(i)
for node in d:
    for child in node[0]:
        if len(d[child][0]) == 0:
            node[1] +=1
    if (node[1] < 3) and (node[1]!=0):
        print("NO")
        break
else:
    print("YES")

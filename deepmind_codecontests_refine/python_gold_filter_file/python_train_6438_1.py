x = input().split(" ")
n = int(x[0])
m = int(x[1])

probInit = set([])
probEnd  = set([])

for i in range(m):
    edge = input().split(" ")
    if edge[0] == "1":
        probInit.add(edge[1])

    if edge[1] == str(n):
        probEnd.add(edge[0])

sec = probEnd.intersection(probInit)
if (len(sec) == 0):
    print("IMPOSSIBLE")
else:
    print("POSSIBLE")

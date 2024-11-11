def kek(nom,soob):
    global graph
    global a
    global uch
    i = 1
    while i <= soob:
        if len(uch) == 0: break
        nom1 = uch[0]
        graph.append([nom+1,nom1+1])
        soob1 = a[nom1]
        uch.pop(0)
        kek(nom1,soob1)
        i += 1

n = int(input())
a = list(map(int,input().split()))
if a[0] == 0 or sum(a) < n:
    print(-1)
    exit
uch = []
a2 = a.copy(); a2.pop(0)
a1 = a.copy(); a1.pop(0); a1.sort(); a1.reverse()
graph = []
for i in a1:
    uch.append(a2.index(i)+1)
    a2[a2.index(i)] = -1
a2.clear()
i = 1
while i <= a[0]:
    if len(uch) == 0: break
    nom = uch[0]
    graph.append([1,nom+1])
    soob = a[nom]
    uch.pop(0)
    kek(nom,soob)
    i += 1
print(len(graph))
i = 0
while i <= len(graph)-1:
    print(graph[i][0],graph[i][1])
    i += 1

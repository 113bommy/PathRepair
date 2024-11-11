# Bosdiwale code chap kr kya milega
# Motherfuckers Don't copy code for the sake of doing it
# ..............
# ╭━┳━╭━╭━╮╮
# ┃┈┈┈┣▅╋▅┫┃
# ┃┈┃┈╰━╰━━━━━━╮
# ╰┳╯┈┈┈┈┈┈┈┈┈◢▉◣
# ╲┃┈┈┈┈┈┈┈┈┈┈▉▉▉
# ╲┃┈┈┈┈┈┈┈┈┈┈◥▉◤
# ╲┃┈┈┈┈╭━┳━━━━╯
# ╲┣━━━━━━┫
# ……….
# .……. /´¯/)………….(\¯`\
# …………/….//……….. …\\….\
# ………/….//……………....\\….\
# …./´¯/…./´¯\……/¯ `\…..\¯`\
# ././…/…/…./|_…|.\….\….\…\.\
# (.(….(….(…./.)..)...(.\.).).)
# .\…………….\/../…....\….\/…………/
# ..\…………….. /……...\………………../
# …..\…………… (………....)……………./

from collections import defaultdict
graph = defaultdict(list)
n,m = list(map(int,input().split()))
for i in range(m):
    u,v = list(map(int,input().split()))
    graph[u-1].append(v-1)
    graph[v-1].append(u-1)
visited = [False for i in range(n)]
parent = [-1 for i in range(n)]
q = []
visited[0] = True
q+=[0]
f = 0
while q!=[]:
    u = q[0]
    q.pop(0)
    for i in graph[u]:
        if visited[i]==False:
            visited[i]=True
            q.append(i)
            parent[i] = u
        elif parent[u]!=i:
            f = 1
cnt = visited.count(True)
if f==0 or cnt!=n:
    print("NO")
else:
    print("FHTAGN!")
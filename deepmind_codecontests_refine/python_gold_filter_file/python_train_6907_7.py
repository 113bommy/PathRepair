import heapq
h = []

params = [int(i) for i in input().split()]
edges = { i+1:[10000000000000000, {}, False, i+1, -1] for i in range(params[0])}
for i in range(params[1]):
    val = [int(j) for j in input().split()]
    amt = val[2]
    if(val[1] in edges[val[0]][1]):
        amt = min(amt, edges[val[0]][1][val[1]])
        edges[val[0]][1][val[1]] = amt
    else:
        edges[val[0]][1].update({val[1]:amt})
    if(val[0] in edges[val[1]][1]):
        amt = min(amt, edges[val[1]][1][val[0]])
        edges[val[1]][1][val[0]] = amt
    else:
        edges[val[1]][1].update({val[0]:amt})

def dijkstra():
    edges[1][0] = 0
    heapq.heappush(h, (edges[1][0], edges[1][3], edges[1][4]))
    while(h):
        val = heapq.heappop(h)
        val = edges[val[1]]
        if(val[3] == params[0]):
            return(0)
        if(val[2]):
            continue
        edges[val[3]][2] = True
        for key in edges[val[3]][1]:
            if(not edges[key][2]):
              num = edges[val[3]][1][key] + edges[val[3]][0]
              #print(num, edges[key][0], key)
              if(num<edges[key][0]):
                edges[key][0] = num
                edges[key][4] = val[3]
                heapq.heappush(h, (edges[key][0], edges[key][3]))
    return -1

if(dijkstra() == -1):
  print(-1)
else:
  arr = [params[0]]
  val = edges[params[0]][4]
  while(not val == -1):
    arr.append(str(val))
    val = edges[val][4]
  arr = reversed(arr)
  print(*arr, sep=' ')
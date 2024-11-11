from sys import stdin,stdout,setrecursionlimit
import threading
     
threading.stack_size(2**26)
setrecursionlimit(10**9)
line1 =[int(x) for x in stdin.readline().split()]
vertexes = line1[0]
edges = line1[1]   
k = line1[2] 
ceiling = k//2 if k % 2 == 0 else (k + 1)/2
     
graph = [[] for _ in range (vertexes + 1)]
parents = [-1 for _ in range(vertexes + 1)]
visited = [0 for _ in range(vertexes + 1)]
depth = [0 for _ in range(vertexes + 1)]
sets = [[] for _ in range(2)]
     
     
while edges > 0 :
    line1 = [int(x) for x in stdin.readline().split()]
    edges -= 1
    graph[line1[0]].append(line1[1])
    graph[line1[1]].append(line1[0])
     
def DFS_Cycle_Visit(vertex) :
    visited[vertex] = 1
    if depth[vertex] < k :
        sets[depth[vertex] % 2].append(vertex)
        
    for ady in graph[vertex]:
        if visited[ady] == 0 :
            parents[ady] = vertex
            depth[ady] = depth[vertex] + 1
            DFS_Cycle_Visit(ady)    
        else:
            current_length = depth[vertex] - depth[ady] + 1
            if 3 <= current_length <= k:
                stdout.write("2\n")
                cycle = []
                i = vertex
                while i != ady:
                    cycle.append(i)
                    i = parents[i]
                cycle.append(ady)
                stdout.write("{}\n".format(len(cycle)))
                for elem in range(len(cycle)-1,-1,-1):  #reversed(cycle) is also right, elem instead of cycle[elem]
                    stdout.write("{} ".format(cycle[elem]))
                exit(0)
                    
     
def DFS_Cycle() :
    for vertex in range(1,len(graph)):
        if visited[vertex] == 0 :
            DFS_Cycle_Visit(vertex + 1)
     
    stdout.write("1\n")
    bigger_set = sets[0]  if len(sets[0]) >= len(sets[1]) else sets[1]
    for elem in range(0,ceiling):
        stdout.write("{} ".format(bigger_set[elem]))
     
threading.Thread(target = DFS_Cycle).start()
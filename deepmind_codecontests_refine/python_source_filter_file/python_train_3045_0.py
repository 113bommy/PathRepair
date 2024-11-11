graph = [[] for i in range(5006)]
def main():
    n, m = map(int, input().split())
    n1, n2, n3 = map(int, input().split())
    for i in range(m):
        x, y = map(int, input().split())
        graph[x].append(y)
        graph[y].append(x)
    graphColoring(n,n1,n2)

def graphColoring(n,n1,n2):
    color = [None] * (n+1)
    bipartitions = []
    for v in range(1,n+1):
        if color[v] is not None:
            continue
        color[v] = 0
        connectedComponents = [[], []]
        connectedComponents[0].append(v)
        S = [v]
        while S != []:
            w = S.pop()
            for u in graph[w]:
                if color[u] is not None:   #cambio aqui
                    if color[u] == color[w]:
                        print("thisNO")
                        return
                    else: continue
                color[u] = color[w] ^ 1
                S.append(u)
                connectedComponents[color[u]].append(u)
        bipartitions.append(connectedComponents)
    answer(bipartitions,n1,n2,n)

def answer(bipartitions,n1,n2,n):

    k = len(bipartitions)
    mat = [[False] * (n2 + 1) for _ in range(k + 1)]
    mat[0][0] = True

    for i in range(1, k + 1):
        for j in range(n2 + 1):
            if j >= len(bipartitions[i - 1][0]) and mat[i - 1][j - len(bipartitions[i - 1][0])]:
                mat[i][j] = True

            if j >= len(bipartitions[i - 1][1]) and mat[i - 1][j - len(bipartitions[i - 1][1])]:
                mat[i][j] = True

    if not mat[k][n2]:
        print("NO")
        return

    idx = [0] * k

    temp = n2
    for i in reversed(range(k)):
    	if temp - len(bipartitions[i][0]) >= 0 and mat[i][temp - len(bipartitions[i][0])]:
    		idx[i] = 0
	    	temp -= len(bipartitions[i][0])
    	elif temp - len(bipartitions[i][1]) >= 0 and mat[i][temp - len(bipartitions[i][1])]:
	    	idx[i] = 1
	    	temp -= len(bipartitions[i][1])


    color = [0] * (n+1)

    for i in range (0,len(bipartitions)):
        if idx[i] == 1:
            while len(bipartitions[i][1]) > 0:
                w = bipartitions[i][1].pop()
                color[w] = 1
        else:
            while len(bipartitions[i][0]) > 0:
                w = bipartitions[i][0].pop()
                color[w] = 1

    res = ""
    for i in range(1,n+1):
        if color[i]:
            res += str(2)
        elif n1 > 0:
            res += str(1)
            n1 -= 1
        else: res+= str(3)
    print("YES")
    print(res)

main()
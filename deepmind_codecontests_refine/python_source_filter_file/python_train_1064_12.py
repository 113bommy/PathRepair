


def run():
    n = int(input())
    input_edges = dict()
    edges = dict()
    for i in range(n-1):
        a, b = list(map(int, input().split()))
        input_edges[(a, b)] = i
        input_edges[(b, a)] = i
        if a in edges:
            edges[a].append(b)
        else:
            edges[a] = [b]
        if b in edges:
            edges[b].append(a)
        else:
            edges[b] = [a]
        
    degrees = dict()
    for i in range(1, n+1):
        l = len(edges[i])
        if l in degrees:
            degrees[l].append(i)
        else:
            degrees[l] = [i]
    
    values_degrees = [-1] * (len(input_edges)//2)
    start_degree = 0
    if 1 in degrees:
        for i in degrees[1]:
            node1 = i
            node2 = edges[i][0]
            j = input_edges[(node1, node2)]
            if values_degrees == -1:
                values_degrees[j] = start_degree
                start_degree += 1

    for i in range(len(values_degrees)):
        if values_degrees[i] == -1:
            values_degrees[i] = start_degree
            start_degree += 1
        print(values_degrees[i])

    


if __name__ == "__main__":
    run()
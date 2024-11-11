n, m, h = map(int, input().split())
a = [0 for i in range(m)]
a[0:m] = map(int, input().split())
b = [0 for i in range(n)]
b[0:n] = map(int, input().split())
toy = [[0 for i in range(m)] for j in range(n)]
for i in range(n):
    toy[i][0:m] = map(int, input().split())
    for j in range(m):
        if toy[i][j] > 0:
            toy[i][j] = max(a[j], b[i])
for i in range(n):
    pout = ""
    for j in range(m):
        if len(pout) > 0:
            pout += " "
        pout += str(toy[i][j])
    print (pout)

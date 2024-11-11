def bfs(mat):
    n = len(mat)
    q = [0]
    visited = [-1] * n
    visited[0] = 0
    while len(q) > 0:
        cur = q.pop()
        for i in range(n):
            if visited[i] == -1 and mat[cur][i] == 1:
                q.append(i)
                visited[i] = visited[cur]+1
    return visited[n-1]

def flip(mat):
    a = [1, 0]
    for i in range(len(mat)):
        for j in range(len(mat)):
            if i != j:
                mat[i][j] = a[mat[i][j]]

def main():
    n, m = [int(i) for i in input().split(" ")]
    mat = [[0]*n for i in range(n)]
    for i in range(m):
        a, b = [int(i) for i in input().split(" ")]
        a -= 1
        b -= 1
        mat[a][b], mat[b][a] = 1, 1
    if mat[0][n-1] == 1:
        flip(mat)
    print(bfs(mat))

if __name__ == "__main__":
    main()

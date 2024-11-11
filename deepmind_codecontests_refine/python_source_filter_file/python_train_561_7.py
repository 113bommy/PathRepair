import sys

def explore_dfs(adj_list, visited, stack, c):
    node = stack.pop()
    if visited[node]:
        return 
    visited[node] = True
    c += 1
    for e in adj_list[node]:
        if visited[e] == False:
            stack.append(e)
    return c

def answer(n, m, k, mat):
    adj_list = [[] for _ in range(n*m + 1)] #first [] will never fill in.
    visited = [False for _ in range(n*m + 1)] #[0] will never change.
    s = 0
    for row in range(n):
        for col in range(m):
            char_p = mat[row][col]
            if char_p == '.':
                s += 1
                pos_p = (row * m + col) + 1
                valid_node = pos_p
                if row - 1 >= 0:
                    pos_c = ((row-1)*m + col) + 1
                    char_c = mat[row-1][col]
                    if char_c == char_p == '.':
                        adj_list[pos_p].append(pos_c)
                        
                if row + 1 < n:
                    pos_c = ((row+1)*m + col) + 1
                    char_c = mat[row+1][col]
                    if char_c == char_p == '.':
                        adj_list[pos_p].append(pos_c)
                        
                if col - 1 >= 0:
                    pos_c = (row*m + (col-1)) + 1
                    char_c = mat[row][col-1]
                    if char_c == char_p == '.':
                        adj_list[pos_p].append(pos_c)
                        
                if col + 1 < m:
                    pos_c = (row*m + (col+1)) + 1
                    char_c = mat[row][col+1]
                    if char_c == char_p == '.':
                        adj_list[pos_p].append(pos_c)
    stack = [valid_node]
    c = 0
    while c < s-k:
        c = explore_dfs(adj_list, visited, stack, c)

    for row in range(n):
        for col in range(m):
            pos_p = (row * m + col) + 1
            if (mat[row][col] == '.') and (visited[pos_p] == False):
                mat[row][col] = 'X'
    
    #for i in range(1, n*m +1):
    #    col = (i - 1) % m 
    #    row = (i - col) // m
    #    if visited[i] == False and mat[row][col] == '.':
    #        mat[row][col] = 'X'
    
    for row in mat:
        print(''.join(row))
    
    return

def main():
    n, m, k = map(int, sys.stdin.readline().split())
    mat = []
    for i in range(n):
        mat.append(list(sys.stdin.readline().rstrip()))
    try:
        answer(n, m, k, mat)
    except:
        print("GregError", sys.exc_info()[0], sys.exc_info()[1], sys.exc_info()[2])
    return

def main2():
    f = open('input.txt')
    n, m, k = map(int, f.readline().split())
    mat = []
    for i in range(n):
        mat.append(list(f.readline().rstrip()))
    answer(n, m, k, mat)
    f.close()
    return

main()
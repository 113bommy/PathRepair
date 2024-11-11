from collections import defaultdict
import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp(): 
    # one integer
    return int(input())
def input_gen_list():
    return input().split()
def input_list():
    # list of integers
    return list(map(int,input().split()))
def input_string():
    # list of characters
    s = input()
    return list(s[:len(s) - 1])
def input_int_gen():
    # integer generator 
    return map(int,input().split())


from collections import defaultdict


#### disjoint sets #### https://medium.com/100-days-of-algorithms/day-41-union-find-d0027148376d
def find(data, i):
    if data[i] != -1:
        data[i] = find(data, data[i])
        return data[i]
    return i
def union(data, i, j):
    pi, pj = find(data, i), find(data, j)
    if pi != pj:
        data[pi] = pj
def connected(data, i, j):
    return find(data, i) == find(data, j)

# Codeforce 747 Div 2 D
tests = inp()
for _ in range(tests):
    n, m = input_int_gen()
    # nodes: (k, b): k: number, b: True if imposter
    # k, b => k + n if b else 0
    # k, True => k + n
    # k, False => k
    data = [-1 for _ in range(2*n+2)]
    if m == 0:
        print(n)
        continue
    for _ in range(m):
        i,j,ci = input_gen_list()
        # print(i,j,ci)
        i = int(i)
        j = int(j)
        c = ci == b"imposter" 
        # print(i,j, c)
        union(data, i + n, j if c else j + n)
        union(data, i, j + n if c else j)
        # print(data)

    impossible = False
    for i in range(1, n+1):
        if connected(data, i + n, i):
            print(-1)
            impossible = True
            break

    # print(data)
    if not impossible:
        teams = [[0,0] for _ in range(2*n+2)]
        for i in range(1, n+1):
            teams[find(data, i + n)][0] += 1
            teams[find(data, i)][1] += 1
        sumi = sum(max(x[0],x[1]) for x in teams)
        print(sumi // 2)
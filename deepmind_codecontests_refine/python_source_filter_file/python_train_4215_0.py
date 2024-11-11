from collections import deque
from sys import stdout

def toposort(graph, indegrees):
    sort = deque()
    zeros = deque()
    for node in indegrees:
        if indegrees[node] == 0:
            zeros.append(node)
    while len(zeros) > 0:
        node = zeros.popleft()
        sort.append(node)
        for to in graph[node]:
            indegrees[to] -= 1
            if indegrees[to] == 0:
                zeros.append(to)
    for node in indegrees:
        if indegrees[node] != 0:
            return None
    return sort


def solve():
    def strcmp(str1, str2):
        if str1 == None:
            return True
        assert not str1 == str2
        if len(str1) < len(str2):
            if str2[:len(str1)] == str1:
                return True
        if len(str1) > len(str2):
            if str1[:len(str2)] == str2:
                return False
        length = min(len(str1), len(str2))
        for i in range(length):
            if str1[i] != str2[i]:
                return (str1[i], str2[i])

    t = int(input().rstrip())
    letters = 'abcdefghijklmnopqrstuvwxyz'
    assert len(letters) == 26
    graph = {}
    indegrees = {}
    for letter in letters:
        graph[letter] = []
        indegrees[letter] = 0
    prev = None
    for i in range(t):
        name = str(input().rstrip())
        val = strcmp(prev, name)
        if val == False:
            return False
        elif val == True:
            pass
        else:
            graph[val[0]].append(val[1])
            indegrees[val[1]] += 1
        prev = name
    sort = toposort(graph, indegrees)
    if sort == None:
        return False
    else:
        assert len(sort) == 26
        return sort

if __name__ == '__main__':
    sort = solve()
    if sort == False:
        print('IMPOSSIBLE')
    else:
        for i in sort:
            stdout.write(str(i))
        stdout.write("\n")

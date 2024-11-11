import os
import sys
from io import BytesIO, IOBase

_str = str
BUFSIZE = 8192


def str(x=b''):
    return x if type(x) is bytes else _str(x).encode()


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = 'x' in file.mode or 'r' not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b'\n') + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode('ascii'))
        self.read = lambda: self.buffer.read().decode('ascii')
        self.readline = lambda: self.buffer.readline().decode('ascii')


def inp():
    return sys.stdin.readline().rstrip()


def mpint():
    return map(int, inp().split(' '))


def itg():
    return int(inp())


# ############################## import
# from ACgenerator.Y_Testing import get_code
def tree_bfs(tree, flat=True, start=0) -> list:
    stack = [start]
    result = []
    while stack:
        new_stack = []
        if flat:
            result.extend(stack)
        else:
            result.append(stack)
        for node in stack:
            new_stack.extend(tree[node])
        stack = new_stack
    return result


def tree_postorder(tree, flat=True, root=0):
    """ children -> parent """
    return tree_bfs(tree, flat, root)[::-1]


def get_parent_list(tree):
    result = [0] * len(tree)
    for parent, children in enumerate(tree):
        for child in children:
            result[child] = parent
    return result


def edge_descendant(tree, edge_time_count=False):
    """
    :return: [{child: num, ...}, ...]
    the number of vertices under each edge

    if edge_time_count:
    the num will translate to the sum of times that walking on the edge
    the walk mean the path of any pair (u, v) and (u < v)
    """
    vertices = len(tree)
    results = [{} for _ in range(vertices)]
    parent_list = get_parent_list(tree)
    for child in tree_postorder(tree):
        parent = parent_list[child]
        if parent != child:
            results[parent][child] = sum(results[child].values()) + 1

    if edge_time_count:
        for parent in results:
            for child in parent:
                num = parent[child]
                parent[child] = num * (vertices - num)
    return results


def node_split_size(tree) -> list:
    """
    return a list for each node, which contains
    the size of each tree if take off the node
    """
    vertices = len(tree)
    results = [list(d.values()) for d in edge_descendant(tree)]
    for descendant in results:
        other = vertices - sum(descendant) - 1
        if other:
            descendant.append(other)
    return results


def to_tree(graph, root=0):
    """
    graph: [{child, ...}, ...]  (undirected)
    :return directed graph that parent -> children
    """
    stack = [[root]]
    while stack:
        if not stack[-1]:
            del stack[-1]
            continue
        parent = stack[-1].pop()
        for child in graph[parent]:
            graph[child].discard(parent)
        stack.append(list(graph[parent]))


def tree_centroid(tree) -> list:
    vertices = len(tree)
    half = vertices >> 1
    split_count = node_split_size(tree)
    centroid = []
    for node, count in enumerate(split_count):
        if max(count) <= half:
            centroid.append(node)
            if vertices & 1 or len(centroid) == 2:
                break
    return centroid


def peek(iterable):
    """
    :return first element in the iterable
    :return None if iterable has nothing
    """
    for element in iterable:
        return element


# ############################## main
def solve():
    n = itg()
    if n & 1:
        for _ in range(n - 2):
            inp()
        ans = inp()
        print(ans)
        print(ans)
        return

    tree = [set() for _ in range(n)]
    for _ in range(n - 1):
        u, v = mpint()
        u -= 1
        v -= 1
        tree[u].add(v)
        tree[v].add(u)

    to_tree(tree)
    centroids = tree_centroid(tree)
    if len(centroids) == 1:
        c1 = centroids[0]
        print(c1 + 1, peek(tree[c1]) + 1)
        print(c1 + 1, peek(tree[c1]) + 1)
        return
    c1, c2 = centroids
    if c2 in tree[c1]:
        c1, c2 = c2, c1
    parent = c1
    leaf = peek(tree[c1])
    while tree[leaf]:  # leaf is not leaf
        parent = leaf
        leaf = peek(tree[leaf])
    print(parent + 1, leaf + 1)
    print(c2 + 1, leaf + 1)


def main():
    # solve()
    # print(solve())
    for _ in range(itg()):
        solve()
        # print("YES" if solve() else "NO")
        # print("yes" if solve() else "no")


DEBUG = 0
URL = ''

if __name__ == '__main__':
    if DEBUG == 1:
        import requests  # ImportError: cannot import name 'md5' from 'sys' (unknown location)
        from ACgenerator.Y_Test_Case_Runner import TestCaseRunner

        runner = TestCaseRunner(main, URL)
        inp = runner.input_stream
        print = runner.output_stream
        runner.checking()
    elif DEBUG == 2:
        main()
    else:
        sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
        main()
# Please check!

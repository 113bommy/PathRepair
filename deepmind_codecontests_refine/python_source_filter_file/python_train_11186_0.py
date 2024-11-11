# ------------------- fast io --------------------
import os
import sys
sys.setrecursionlimit(10**5)
from io import BytesIO, IOBase

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
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
            self.newlines = b.count(b"\n") + (not b)
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
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

# ------------------- fast io --------------------

class Trie:
    class Node:
        def __init__(self, char: str = "*"):
            self.char = char
            self.children = []
            self.word_finished = False
            self.counter = 1

    def __init__(self):
        self.root = Trie.Node()

    def add(self, word: str):
        node = self.root
        for char in word:
            found_in_child = False
            for child in node.children:
                if child.char == char:
                    child.counter += 1
                    node = child
                    found_in_child = True
                    break
            if not found_in_child:
                new_node = Trie.Node(char)
                node.children.append(new_node)
                node = new_node
        node.word_finished = True

    def query(self, prefix, root=None):
        if not root: root = self.root
        node = root
        if not root.children:
            return 0
        for char in prefix:
            char_not_found = True
            for child in node.children:
                if child.char == char:
                    char_not_found = False
                    node = child
                    break
            if char_not_found:
                return 0
        return node


n, k = map(int, input().split())
tr = Trie()
for _ in range(n):
    tr.add(input())

def can_win(node):
    if not node.children:
        return False
    for child in node.children:
        if not can_win(child):
            return True
    return False

def can_lose(node):
    if not node.children:
        return True
    for child in node.children:
        if can_win(child):
            return True
    return False

pos = can_win(tr.root)
pos2 = can_lose(tr.root)

if pos and pos2:
    print("First")
elif not pos:
    print("Second")
else:
    print("First" if k % 2 else "Second")
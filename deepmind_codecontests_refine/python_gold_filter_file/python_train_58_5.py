class MemManager:
    def __init__(self, m):
        self.size = m
        self.currID = 1
        self.blocks = []
        self.IDlist = []

    def alloc(self, n):
        start = 1
        index = 0
        numBlocks = len(self.blocks)
        while index < numBlocks and self.blocks[index][0] - start < n:
            start = self.blocks[index][1]
            index += 1
        if start + n <= self.size+1:
            self.blocks.insert(index, [start, start + n])
            self.IDlist.insert(index, self.currID)
            print(self.currID)
            self.currID += 1
        else:
            print('NULL')

    def erase(self, x):
        if x in self.IDlist:
            index = self.IDlist.index(x)
            del self.IDlist[index]
            del self.blocks[index]
        else:
            print('ILLEGAL_ERASE_ARGUMENT')

    def defragment(self):
        start = 1
        numBlocks = len(self.blocks)
        for i in range(numBlocks):
            k = self.blocks[i][0] - start
            for j in range(2):
                self.blocks[i][j] -= k
            start = self.blocks[i][1]

    def debug(self):
        for b in self.blocks:
            print(b)
        print(self.IDlist)

t, m = map(int, input().split())
berl = MemManager(m)
for _ in range(t):
    cmd = input().split()
    if cmd[0] == 'alloc':
        berl.alloc(int(cmd[1]))
    elif cmd[0] == 'erase':
        berl.erase(int(cmd[1]))
    elif cmd[0] == 'defragment':
        berl.defragment()
    else:
        berl.debug()

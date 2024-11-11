import heapq

def d_manhattan(node_list):
    s = 0
    for i in range(9):
        x_goal = i%3
        y_goal = i//3
        x_now = (node_list[i] - 1)%3
        y_now = (node_list[i] - 1)//3
        if y_now == -1:
            y_now = 2
        dx = abs(x_now - x_goal)
        dy = abs(y_now - y_goal)
        s += dx + dy
    return s

def moveNodeE(node_list, space):
    node_tmp = node_list[:]
    node_tmp[space], node_tmp[space + 1] = node_tmp[space + 1], node_tmp[space]
    return node_tmp
def moveNodeW(node_list, space):
    node_tmp = node_list[:]
    node_tmp[space], node_tmp[space - 1] = node_tmp[space - 1], node_tmp[space]
    return node_tmp
def moveNodeN(node_list, space):
    node_tmp = node_list[:]
    node_tmp[space], node_tmp[space - 3] = node_tmp[space - 3], node_tmp[space]
    return node_tmp
def moveNodeS(node_list, space):
    node_tmp = node_list[:]
    node_tmp[space], node_tmp[space + 3] = node_tmp[space + 3], node_tmp[space]
    return node_tmp

class board:
    def __init__(self, node_list, g):
        self.node = node_list
        self.space = node_list.index(0)
        self.g = g
        self.h = d_manhattan(node_list)
        self.f = self.g + self.h

    def makeBoard(self):
        space = self.space
        cost_now = self.f
        x_s = space%3
        y_s = space//3
        if x_s < 2:
            node_tmp = moveNodeE(self.node, space)
            yield board(node_tmp, self.g + 1)
        if x_s > 0:
            node_tmp = moveNodeW(self.node, space)
            yield board(node_tmp, self.g + 1)
        if y_s < 2:
            node_tmp = moveNodeS(self.node, space)
            yield board(node_tmp, self.g + 1)
        if y_s > 0:
            node_tmp = moveNodeN(self.node, space)
            yield board(node_tmp, self.g + 1)

b_open = []
n_close = {}
n_goal = [1,2,3,4,5,6,7,8,0]
n_start = []

for i in range(3):
    inp = list(map(int, input().split()))
    n_start.extend(inp)

b_start = board(n_start, 0)
heapq.heappush(b_open, (b_start.f, b_start.h, 0, b_start))

i = 0
while b_open:
    _, _, _, b_now = heapq.heappop(b_open)
    if b_now.node == n_goal:
        b_goal = b_now
        break
    n_close["".join(map(str, b_now.node))] = i
    for b_new in b_now.makeBoard():
        if "".join(map(str, b_new.node)) in n_close:
            continue
        heapq.heappush(b_open, (b_new.f, b_new.h, i, b_new))
        i += 1

print(b_goal.g)
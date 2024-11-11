class Node(object):
    cnt = 0

    def __init__(_, adj=None):
        _.id = Node.cnt
        Node.cnt += 1
        _.adj = adj if adj else []
        _.seen = False

    def dfs(_):
        if _.seen:
            return
        _.seen = True
        for i in _.adj:
            ans[_.id][i.id] = ans[_.id][i.id] = 'Y'
            i.dfs()

n = int(input())
start = Node()
end = Node()
choose = Node()
for i in range(30):
    if n & (1<<i):
        choose.adj.append(end)
    if i == 29:
        break
    end = Node([Node([end]), Node([end])])
    choose = Node([Node([choose])])

start.adj.append(choose)
ans = [['N'] * Node.cnt for i in range(Node.cnt)]
start.dfs()

print(Node.cnt)
for line in ans:
    print(''.join(line))

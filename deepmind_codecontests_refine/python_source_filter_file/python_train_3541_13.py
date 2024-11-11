import collections

def search(node, elems, tree, depth):
    elems[node].append(depth)
    if elems[node][0] == -1:
        state = 'root'
    elif not tree[node]:
        state = 'leaf'
    else:
        state = 'internal node'
    elems[node].append(state)
    elems[node].append(tree[node])
    depth += 1
    for c in tree[node]:
        search(c, elems, tree, depth)
    
if __name__ == '__main__':
    n = int(input())
    tree = collections.defaultdict(list)
    elems = collections.defaultdict(list)
    #elems key:id, value: parent, depth, state, children
    parents = list()
    node_list = list()
    for _ in range(n):
        hoge = [int(x) for x in input().split()]
        node_list.append(hoge[0])
        tree[hoge[0]]
        for childs in range(hoge[1]):
            tree[hoge[0]].append(hoge[childs+2])
    
    for key, value in tree.items():
        for v in value:
            elems[v].append(key)
    for node in node_list:
        if not elems[node]:
            parents.append(node)
            elems[node].append(-1)
    
    for p in parents:
        search(p, elems, tree, 0)
        
    for key, value in elems.items():
        print('node {0}: parent = {1[0]}, depth = {1[1]}, {1[2]}, '.format(key, value), end='')
        print (value[-1])

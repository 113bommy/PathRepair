def f1(l1):
    ret = []
    for i in l1:
      for n,j in enumerate(li[i]):
        if j:
            if n in used or n in l1:
                return False
            elif n not in tree[nest-1] and n not in ret:
                ret.append(n)
    return ret


N = int(input())
li = []
for _ in range(N):
    li.append(list(map(int,list(input()))))
    
max_nest = 0
for i in range(N):
    tree = [[]]
    used = []
    tree.append([i])
    nest = 1
    while True:
        ret = f1(tree[nest])
        nest += 1
        if ret == False:
            break
        elif ret != []:
            tree.append(ret)
            used.extend(tree[nest-2])
        else:
            if max_nest < nest:
                max_nest = nest
            break
        
print(max_nest-1)
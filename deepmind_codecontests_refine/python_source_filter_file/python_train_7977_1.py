n=int(input())
dick = {}
boy = 1
tree = [int(input()) for i in range(n-1)]
#tree.sort()
heads = set()
for i in tree:
    boy=boy+1
    dick[boy]=i
    if i not in heads:
        heads.add(i)
    if i in dick:
        dick.pop(i)
#print(dick)
tree={}
for i in heads:
    tree[i]=1
for i in dick:
    if dick[i] in tree:
        tree[dick[i]]+=1
    else:
        tree[dick[i]]=1
#print(tree)
def chk(tree):
    for i in tree:
        if tree[i]<3:
            return "No"
    return "Yes"
                                                                                                        
print(chk(tree))


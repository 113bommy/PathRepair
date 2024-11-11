n = int(input()) # number of vertices
a = list(map(int,input().split())) # connection
b = list(map(int,input().split())) # colour
tree = []
for i in range(1,n + 1):
    tree.append([i])
for j in range(2,n + 1):
    tree[b[j - 2] - 1].append(j)
s = 0
for each in tree:
    if len(each) == 1:
        s += 1
        tree.remove(each)
for subset in tree:
    subset = list(map(lambda x: b[x - 1],subset))
    colour = subset[0]
    s = s - subset.count(colour) + 2
print (s)

a=[*open(0)][1].split()
a=[a.count(x)for x in {*a}-{'0'}]
print([a.count(2),-1][max(a+[0])>2])
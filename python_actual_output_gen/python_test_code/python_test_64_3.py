input()
h = list(map(int,input().split()))
m = h[-1]
n = []
for x in h[::-1]:
    n.append(str(m-x))
    m = max(m,x+1)
print (' '.join(n[::-1]))

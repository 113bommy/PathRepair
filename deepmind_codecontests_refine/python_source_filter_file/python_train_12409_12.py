l,r = map(int , input().split())
for i in range(l,r):
    g = str(i)
    if len(set(g))==len(g):
        print(g)
        exit()
print('-1')


a,b = map(int,input().split())
cur,dead = a,0
h = a
while cur>1:
    dead += cur
    cur = dead//b
    dead = dead%b
    h += cur

print(h)
k = input()
s = input()
r=""
l=['q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/']
if k == 'R':
    for i in s:
        t = l.index(i)
        r=r+l[t-1]
else:
    for i in s:
        t = l.index(i)
        r=r+l[t-1]
print(r)
input()
l = sorted(list(map(int, input().split())))
t = 0
c = 0
for x in l:
    if t<=x:
        t+=x
        c+=1
print (c)
from functools import reduce
f,o,t = map(int, input().split(' '))
res = [0 for i in range(o)]
for i in range(f):
    s = input()
    for j in range(o):
        res[j]+=(s[j]=='Y')
print(reduce(lambda x,y: x+(y>=t), res,0))

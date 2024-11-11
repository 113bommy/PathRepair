x,y = map(int,input().split())
a = [(i,i) for i in range(min(x,y)+1)]
print(len(a))
for i in a:
    print(*(i), sep = ' ')
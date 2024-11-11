input()
o,t=0,0
l=sorted(list(map(int,input().split())))
for i in l:
    if i>=t:
        o+=1
    t+=i
print(o)
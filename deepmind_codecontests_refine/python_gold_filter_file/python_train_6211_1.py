d = {}
l =[]
for i in range(int(input())):
    a,b,c = map(int,input().replace("(","").replace(")/"," ").replace("+"," ").split())
    ans = (a+b)/c
    l.append(ans)
    if ans in d: d[ans]+=1
    else: d[ans]=1

for i in l:
    print(d[i],end=" ")

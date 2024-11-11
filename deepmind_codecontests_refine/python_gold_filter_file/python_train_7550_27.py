from collections import Counter
input()
s=input()
c = Counter(s)
res = sum([x-1 for _,x in c.items()])
if res+len(c)>26 : print(-1); exit()
else : print(res)

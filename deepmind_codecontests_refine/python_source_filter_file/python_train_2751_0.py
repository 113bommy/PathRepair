import heapq

s = input()
sl = list(s)
ct = 0
cost = 0
flag = True
h = []
for i,c in enumerate(s):
    if c == '(':
        ct+=1
    elif c == ')':
        ct-=1
    else:
        l,r = map(int,input().split())
        sl[i] = ')'
        cost += r
        ct-=1
        heapq.heappush(h,(l-r,i))
    if ct<0:
        if not h:
            flag = False
            break
        # print("Fuck "+"".join(sl))
        d,pos = heapq.heappop(h)
        sl[pos] = '('
        ct+=2
        cost += d
    if(ct<0):
        pass
        # flag = False
        # break
if ct < 0 or flag == False:
    print(-1)
else:
    print(cost)
    print("".join(sl))

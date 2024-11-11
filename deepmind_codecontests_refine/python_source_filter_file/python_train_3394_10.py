n, a = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]
d = {}
d[a] = 0
t = True
for x in c:
    if(x == a):
        t == False
        d[a]+=1
    else:
        if(t):
            if(x in d):
                d[x]+=1
            else:
                d[x]=1
        else:
            if(x not in d):
                continue
            else:
                if(d[x]>=d[a]):
                    d[x]+=1
                else:
                    d.pop(x)
k = True
for x in d:
    if(x!= a and d[x]>=d[a]):
        print(x)
        k = False
        break
if(k):
    print(-1)

        
            

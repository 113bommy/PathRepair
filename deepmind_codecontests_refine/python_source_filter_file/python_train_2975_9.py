l=[]
for i in range(3):
    x,y = map(int,input().split())
    l.append([x,y])

print(l)
S = set()

def calc(a):
    ans = 0
    n = len(a)
    for i in range(n):
        ans += a[i][0]*a[(i+1)%n][1] - a[i][1]*a[(i+1)%n][0]
    return ans
    
for i in range(3):
    for j in range(3):
        if i== j:
            continue
        for k in range(3):
            if i==k or i == j:
                continue
            x = l[i][0] + l[j][0] - l[k][0]
            y = l[i][1] + l[j][1] - l[k][1]
            new = []
            new.append(l[i])
            new.append(l[k])
            new.append(l[j])
            new.append([x,y])
            if calc(new) > 0: 
                S.add(tuple([x,y]))
            

print(len(S))
for i in S:
    print(i[0],i[1])

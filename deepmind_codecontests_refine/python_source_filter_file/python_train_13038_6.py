t = int(input())
mn = []
m = []
n = []
result = []
for i in range(t):
    mn.append(list(map(int,input().strip().split(" "))))
    n.append(mn[i][0])
    m.append(mn[i][1])

for i in range(t):
    if(n[i]%2==0 or m[i]%2 == 0):
        result.append((n[i]*m[i])/2)
    elif(n[i] == 1 and m[i] ==1):
        result.append(1)
    elif(n[i] == 1 and m[i] % 2==1 ):
        result.append((m[i]+1)/2)
    elif(n[i] == 1 and m[i] % 2==0):
        result.append(m[i]/2)
    elif(m[i] == 1 and n[i] % 2==1):
        result.append((n[i]+1)/2)
    elif(m[i] == 1 and n[i] % 2==0):
        result.append(n[i]/2)
    else:
        result.append(((n[i]-1)*m[i]/2)+m[i]-1 )
        
for i in result:
    print(int(i))
        
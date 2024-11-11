
l,d,v,g,r = map(int,input().split())

t = l/v
t1 = d/v
k = [[0,g,'g']]
# print(t1)
for i in range(1,2000):
    if i%2 == 0:
        k.append([k[i-1][1],k[i-1][1]+g,'g'])
    else:
        k.append([k[i-1][1],k[i-1][1]+r,'r'])
# print(k)
for j in k:
    a,b,c = j
    if a<=t1<=b:
        if c == 'g':
            print(t)
            break
        else:
            print(t1+abs(b-t1)+(l-d)/v)
            break

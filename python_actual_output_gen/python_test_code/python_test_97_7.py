n = int(input())

ol = []
ne = []

for i in range(n):
    x = input().split(" ")
    
    try:
        c = ne.index(x[0])
        new[c] = x[1]
    except:
        ol.append(x[0])
        ne.append(x[1])

print (len(ol))
for i in range(len(ol)):
    print (ol[i]+" "+ne[i])
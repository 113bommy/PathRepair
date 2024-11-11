cities , pairs = map(int,input().split())
 
road1 = {}
road2 = {}
 
if pairs == 0 :
    print(cities - 1)
    for i in range(2 , cities + 1):
        print(1 , i)
 
else:
    for i in range(pairs):
        u , v = (map(int,input().split()))
        road1[u] = v
        road2[v] = u
 
    print(cities - 1)
    k = 0
    for j in range(1 , cities + 1):
        if j not in road1 and j not in road2 :
            k = j
            break
 
    for j in range(1 , cities + 1 ):
        if j == k :
            continue
        else:
            print(k , j)
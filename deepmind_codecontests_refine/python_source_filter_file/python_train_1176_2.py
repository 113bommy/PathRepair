t = int(input())

for hg in range(t) :
    n , k = map(int , input().split())
    
    l = []
    for i in range(k + 1 , n + 1):
        l.append(i)
        
    for i in reversed(range(0 , k - 1)):
        d = k - i
        if d not in l:
            l.append(i)
    
    print(len(l))
    for i in l:
        print(int(i) , end = " ")
    print()
from collections import Counter
for r in range(int(input())):
    n,x = map(int,input().split())
    l=[]
    for u in range (n-1):
            a,b = map(int,input().split())
            l.append(a)
            l.append(b)
    #print(l)
    l = Counter(l)
    #print(l)
    if l[x]<2:
        print('Ayush')
    elif l[x]%2:
        print('Ashish')
    else:
        print('Ayush')
    
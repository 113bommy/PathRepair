n, m, k, t = map(int, input().split())
a = []
for i in range(k):
    b, c = map(int, input().split())
    a.append([b,c])
a.sort()
for i in range(t):
    d, e = map(int, input().split())
    if [d, e] in a:
        print('Waste')
    else:
        g = (d-1)*m + (e-1)
        #print(g)
        h = 0
        #print(k)
        for i in range(k):
            #print(d,a[i][0])
            if(d > a[i][0]):
                h += 1
            elif(d == a[i][0] and e > a[i][1]):
                h += 1
        
        #print(g-h,h,k)
        v = (g-h)%3
        #print(v)
        if(v == 0):
            print('Carrots')
        elif(v == 1):
            print('Kiwis')
        else:
            print('Grapse')
    
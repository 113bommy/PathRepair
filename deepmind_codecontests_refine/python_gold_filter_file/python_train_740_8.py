n = int(input())
 
a = list(map(int, input().split()))
 
d = {}
 
for i in a :
    if d.get(i) :
        d[i] += 1
    else :
        d[i] = 1

b = [[0 for i in range (n)] for j in range (n)]
a.sort()
ind = 0
p = 0
#print(d)
#print(a)

if n%2 == 0 :
    for i in range (n//2) :
        t = 0
        for j in range (n//2) :
            if d[a[ind]] > 3 :
                b[i][j] = a[ind]
                b[-1-i][j] = a[ind]
                b[i][-1-j] = a[ind]
                b[-1-i][-1-j] = a[ind]
                
                d[a[ind]] -= 4
                ind += 4
            else :
                #print(a[ind],d[a[ind]],ind)
                p = 1
                t = 1
                break
        if t :
            break

else :
    i = 0
    l = len(a)
    while i<(n//2) :
        j = 0
        t = 0
        while j<(n//2) :
            if (ind>=l) :
                p = 1
                t = 1
                break
            if d[a[ind]] > 3 :
                b[i][j] = a[ind]
                b[-1-i][j] = a[ind]
                b[i][-1-j] = a[ind]
                b[-1-i][-1-j] = a[ind]
                
                d[a[ind]] -= 4
                ind += 4
                j+=1
            else :
                #print(a[ind],d[a[ind]],ind)
                ind += d[a[ind]]
        if t :
            break
        i += 1

    
    j = 0
    if p == 0 :
        for i in d :
            while d[i] > 1 and j < n//2 :
                b[j][n//2] = i
                b[-1-j][n//2] = i
                d[i] -= 2
                j += 1
    
    j = 0
    if p == 0 :
        for i in d :
            while d[i] > 1 and j < n//2 :
                b[n//2][j] = i
                b[n//2][-1-j] = i
                d[i] -= 2
                j += 1

    
    x = 0
    if p == 0 :
        for i in d :
            if d[i]>0 and x == 0 :
                b[n//2][n//2] = i
                x = 1
            elif d[i] > 0 and x == 1 :
                p = 1
                #print(d[i],i)
                break


    
                
if p :
    print("NO")
else :
    print("YES")
    for i in range (n) :
        for j in range(n) :
            print(b[i][j],end=" ")
        print()

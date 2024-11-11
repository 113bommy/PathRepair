


n,s = map(int,input().split())
t=[[0,0]]
for j in range(n):

    a,b = map(int,input().split())


    total = a*60+b


    last = t[-1][0]*60+t[-1][1]+1

    t.append([a,b])

    if j==0:
        if total> s+1:
            print(0,0)
            break
    if total-last > 2*s:
        u = last+s
        print(u//60, u%60)
        break

    if j==n-1:
        x = t[-1][0]*60+t[-1][1]
        print((x+s+1)//60 ,(x+s+1)%60 )
        break


    
    

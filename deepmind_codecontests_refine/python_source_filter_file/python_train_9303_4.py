n,m,k = map(int,input().split())
a = [int(x) for x in input().split()]
a = sorted(a,reverse=True)
minNum = min(a)
if k >= m :
    print(0)
else:
    if k != 1:
        m = m - k +1
    else:
        m = m - k
    c = 0
    i = 0

    while(i < n and m > 0 ):
            if a[i] == m:
                    #print("j",a[i], m)
                    m = m - a[i]
                    c+=1
            elif (a[i] >= m ):
                    c+=1
                    m = 0
                    break
            elif( m-a[i]+1 >= minNum):
                    #print(m,a[i])
                    m = m - a[i] + 1
                    c+=1
            i = i+1

    if m!=0 :
        print(-1)
    else:
        print(c)

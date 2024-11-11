def answer():
    n = int(input())
    c=[]
    while n:
        a = [int(x) for x in input().split()[1:]]
        c.append(a)
        n-=1
    def myfunc(e):
        return e[0]
    c.sort(key=myfunc)
    c.reverse()

    i=0
    #print(c)
    done=0
    while i<len(c):
        if c[i][0]>=2400 and c[i][1]>c[i][0]:
            print("YES")
            done=1
            break  
        i+=1
    if not done:
        print("NO")
answer()

t = int(input())
for g in range(0, t):
    nx = list(map(int,input().split()))
    n = nx[0]
    #print(n)
    x = nx[1]
    #print(x)
    arr=list(map(int,input().split()))
    t=set(arr)
    a=[]
    for i in range(1,1000):
        if i in t:
            continue
        elif(x>0):
            a.append(i)
            x=x-1
        else:
            break
    t=list(t)
    for i in range(0,len(a)):
        t.append(a[i])
    t=set(t)
    t=list(t)
    for i in range(0,len(t)):
        if(t[i]==i+1):
            i=i+1
        else:
            break
    print(i)

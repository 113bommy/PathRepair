def ps2(low,high):
    global flag
    if flag:
        t=-1
        for i in range(low,high+1):
            t+=1
            i= (i)%475
            for _ in range(25):
                i=(i*96+42)%475
                r=i+26
                if r == p:
                    result.append(t)
                    flag=False
                    break
            if flag == False:
                break
def ps1(low,high):
    global flag
    if flag:
        t=-1
        for i in range(high,low-1,-1):
            t+=1
            jjj=i
            i= (i)%475
            for _ in range(25):
                i=(i*96+42)%475
                r=i+26
                if r == p:
                    result.append(t)
                    flag=False
                    break
            if flag == False:
                break
p,x,y=map(int,input().split())
result=[]
if x < y:
    mid=y
    if y % 50 != 0:
        mid+=1
    #high=99**9
    mid//=50
    high=99999999990
    flag=True
    ps2(mid,high)
    tt=mid-(x//50)
    for i in range(len(result)):
        p=result[i]
        if p % 2 == 0:
            result[i]=int(p/2)
        else:
            result[i]=int((p+1)/2)
    print(min(result)+tt)
else:
    low=y
    mid=x
    #high=99**9
    low //=50
    mid //=50
    if (x-y) % 50 != 0:
        low+=1
    high=99999999990
    #1
    flag=True
    ps1(low,mid)
    if len(result) > 0:
        print(0)
    else:
        #2
        flag=True
        ps2(mid,high)
        for i in range(len(result)):
            p=result[i]
            if p % 2 == 0:
                result[i]=int(p/2)
            else:
                result[i]=int((p+1)/2)
        print(min(result))
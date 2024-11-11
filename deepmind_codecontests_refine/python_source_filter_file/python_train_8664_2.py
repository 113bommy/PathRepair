n,m=map(int,input().split())
li=list(map(int,input().split()))
sumli=sum(li)
if sumli<n:print(-1)
else:
    deficiency=n-m
    for i in range(m):
        if i+li[i]>n-1:
            print(-1)
            break
    else:
        i=n-li[-1]
        deficiency-=li[-1]-1
        output=[i]
        z=m-2
        while deficiency>0:
            deficiency-=li[z]-1
            if deficiency>=0:
                output.append(output[-1]-li[z])
            else:output.append(output[-1]+deficiency-li[z])
            z-=1
        for i in range(z,-1,-1):
            output.append(i)
        output.reverse()
        output=list(map(lambda i:i+1,output))
        print(*output)
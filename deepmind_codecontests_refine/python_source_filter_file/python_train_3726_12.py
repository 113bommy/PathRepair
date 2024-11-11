n=int(input())

def bai(x):
    return int(x)*2.0

xy=[list(map(bai, input().split())) for _ in range(n)]

#nは50だから4重ループでも間に合う？
#2500*2500

if n==2:
    print((((xy[0][0]-xy[1][0])**2 +(xy[0][1]-xy[1][1])**2) **0.5)*0.5)
    exit()

ans=10**9

def gaishin(a,b,c,d,e,f):
    if (a-c)*(d-f)==(c-e)*(b-d):
        y=(max([b,d,f])-min([b,d,f]))/2.0+min([b,d,f])
        x=(max([a,c,e])-min([a,c,e]))/2.0+min([a,c,e])

        #print(a,b,c,d,e,f,"==>",x,y)

    else:
        y=1.0*((e-a)*(a**2+b**2-c**2-d**2)-(c-a)*(a**2+b**2-e**2-f**2))/(2.0*(e-a)*(b-d)-2.0*(c-a)*(b-f))
        if e-a!=0:
            x=(2.0*(b-f)*y-a**2-b**2+e**2+f**2)/(2.0*(e-a))
        elif c-a!=0:
            x=(2.0*(b-d)*y-a**2-b**2+c**2+d**2)/(2.0*(c-a))
        else:
            print(a,b,c,d,e,f)
            exit()

    return x,y

xy.sort()

for i in range(n-2):
    for j in range(i+1,n-1):
        for k in range(i+2,n):
            #print(xy[i],xy[j],xy[k])

            gx,gy=gaishin(xy[i][0],xy[i][1],xy[j][0],xy[j][1],xy[k][0],xy[k][1])
            d=((1.0*(gx-xy[i][0]))**2+(1.0*(gy-xy[i][1]))**2)
            flag=0
            #print(gx,gy)
            for (x,y) in xy:
                if (x,y) != xy[i] and (x,y) != xy[j] and (x,y) != xy[k]:
                    if ((1.0*(gx-x))**2+(1.0*(gy-y))**2) >d:
                        flag=1
                        #print(((1.0*(gx-x))**2+(1.0*(gy-y))**2)**0.5,"-",d,"=",((1.0*(gx-x))**2+(1.0*(gy-y))**2)**0.5-d) 
                        break
            if flag==0:
                ans=min(ans,d**0.5)
                #print(">>>>",xy[i],xy[j],xy[k],d**0.5,gx,gy)

print(ans/2)







import sys
input = sys.stdin.readline
n = int(input())
if n == 1:
    ans = 0

else:
    u_list, d_list, r_list, l_list = [],[],[],[]
    x_list, y_list = [],[]

    for i in range(n):
        x, y, r = [ v for v in input().split() ]
        x, y, = int(x), int(y)
        
        if r == "U":
            u_list.append(y)
            x_list.append(x)
        elif r == "D":
            d_list.append(y)
            x_list.append(x)
        elif r == "R":
            r_list.append(x)
            y_list.append(y)
        elif r == "L":
            l_list.append(x)
            y_list.append(y)

    x_list = sorted(x_list)
    y_list = sorted(y_list)
    u_list = sorted(u_list)
    d_list = sorted(d_list)
    r_list = sorted(r_list)
    l_list = sorted(l_list)

    if len(u_list) == n:
        ans = (x_list[-1]-x_list[0])*(u_list[-1]-u_list[0])
    elif len(d_list) == n:
        ans = (x_list[-1]-x_list[0])*(d_list[-1]-d_list[0])
    elif len(r_list) == n:
        ans = (y_list[-1]-y_list[0])*(r_list[-1]-r_list[0])
    elif len(l_list) == n:
        ans = (y_list[-1]-y_list[0])*(l_list[-1]-l_list[0])
    #t1:y+ max(y[-1],u-1,d-1)
    #t2,y- min(y[0],u0,d0)
    #t3,x+ max(x-1,l-1,r-1)
    #t4,x- max(x0,l0,r0)
    else:
        yp_list = []
        ym_list = []
        xp_list = []
        xm_list = []
        if y_list != []:
            yp_list.append((y_list[-1],0))
            ym_list.append((y_list[0],0))
        if u_list != []:
            yp_list.append((u_list[-1],1))
            ym_list.append((u_list[0],1))
        if d_list != []:
            yp_list.append((d_list[-1],-1))
            ym_list.append((d_list[0],-1))
        if x_list != []:
            xp_list.append((x_list[-1],0))
            xm_list.append((x_list[0],0))
        if r_list != []:
            xp_list.append((r_list[-1],1))
            xm_list.append((r_list[0],1))
        if l_list != []:
            xp_list.append((l_list[-1],-1))
            xm_list.append((l_list[0],-1))


        time_list = []

        def timemotome(inlist1,inlist2):
            ti = (inlist1[0] - inlist2[0]) / (inlist2[1] - inlist1[1])
            return ti

        def timemotome2(inlist):
            if len(inlist) == 2:
                t = timemotome(inlist[0],inlist[1])
                if t >= 0:
                    time_list.append(t)
            elif len(inlist) == 3:
                t = timemotome(inlist[0],inlist[1])
                if t >= 0:
                    time_list.append(t)
                t = timemotome(inlist[1],inlist[2])
                if t >= 0:
                    time_list.append(t)
                t = timemotome(inlist[2],inlist[0])
                if t >= 0:
                    time_list.append(t)

        timemotome2(xm_list)
        timemotome2(xp_list)
        timemotome2(yp_list)
        timemotome2(ym_list)

        def menseki(a):
            ymax = max([ i[0] + i[1]*a for i in yp_list])
            ymin = min([ i[0] + i[1]*a for i in ym_list])
            xmax = max([ i[0] + i[1]*a for i in xp_list])
            xmin = min([ i[0] + i[1]*a for i in xm_list])
            return (ymax - ymin) * (xmax - xmin) 
        ans = 10**17
        for i in list(set(time_list)):
            ans = min(menseki(i),ans)

print(ans)
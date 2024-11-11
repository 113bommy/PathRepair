for t in range(int(input())):
    n,ti,a,b=map(int,input().split())
    aa=list(map(int,input().split()))
    bb=list(map(int,input().split()))
    c=[]
    count_eb=0
    count_hb=0
    count_ef=0
    count_hf=0
    for i in range(n):
        c.append([bb[i],aa[i]])
        if(aa[i]==1):
            count_hb+=1
        else:
            count_eb+=1
    c.sort()
    c.append([ti+1,0])
    count=0
    store=0
    for i in range(n+1):
        diff=count_hf*b+count_ef*a
        count=0
        if(diff<=(c[i][0]-1) and diff<=ti):
            count=i
            vac_e=abs(diff-c[i][0]+1)
            if(count_eb*a>vac_e//a):
                rem=vac_e//a
            else:
                rem=count_eb
            count+=rem
            vac_h=abs(vac_e-rem*a)
            if(count_hb*b<vac_h//b):
                count+=count_hb
            else:
                count+=vac_h//b
        store=max(store,count)
        if(c[i][1]==1):
            count_hb-=1
            count_hf+=1
        else:
            count_eb-=1
            count_ef+=1
    print(store)
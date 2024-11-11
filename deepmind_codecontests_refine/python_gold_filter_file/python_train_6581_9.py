t=int(input())
while t > 0:
    n=int(input())
    seq=input()
    dict={}
    h=v=0
    L=R=-1
    dis=300000
    dict[(0,0)]=0
    possible =False
    for i in range(n):
        if seq[i]=='L':
            h-=1
        elif seq[i]=='R':
            h+=1
        elif seq[i]=='U':
            v+=1
        else:
            v-=1
        tup=(h,v)
        #repeated path
        if tup in dict:
            l=dict[tup]+1
            r=i+1
            if((r-l+1)<dis):
                L=l;R=r;dis=r-l+1
            dict[tup]=i+1
            possible = True
        else:
            dict[tup]=i+1
    if possible:
        print(L,R)
    else:
        print('-1')
    t-=1

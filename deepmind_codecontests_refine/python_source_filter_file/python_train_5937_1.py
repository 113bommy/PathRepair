while input()!='0':
    l=list(map(float,input().split()))
    m=sum(l)/len(l)
    s=0
    for i in range(len(l)):
        s+=(l[i]-m)**2
    print('%.8f'%(s/len(l)**.5))
t=int(input());a=[None]*t;b=[None]*t;c=[None]*t;d=[None]*t
for i in range(0,t): 
    a[i],b[i],c[i],d[i]=map(int, input().split())
    if (a[i]+b[i])%2==0:
        if (a[i],d[i])==(0,0): print('Tidak Tidak Ya Tidak')
        elif (b[i],c[i])==(0,0): print('Tidak Tidak Tidak Ya')
        else: print('Tidak Tidak Ya Ya')
    else:
        if (a[i],d[i])==(0,0): print('Tidak Ya Tidak Tidak')
        elif (b[i],c[i])==(0,0,0): print('Ya Tidak Tidak Tidak')
        else: print('Ya Ya Tidak Tidak')
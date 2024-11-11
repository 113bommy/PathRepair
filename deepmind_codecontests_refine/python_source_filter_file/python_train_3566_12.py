for _ in range(int(input())):
    n=int(input())
    lis=list(map(int,input().split()))
    if n%2==0:
        diff=[]
        su=0
        for i in range(0,n,2):
            su+=lis[i]
            diff.append(lis[i]-lis[i+1])
        mi=0
        fi=0
        for i in range(n//2):
            fi+=diff[i]
            if fi<0:
                if fi<mi:
                    mi=fi
            else:
                fi=0
        m1=su-(mi)
        dif2=[]
        for i in range(1,n-1,2):
            dif2.append(lis[i]-lis[i+1])
        ma=0
        fi=0
        for i in range(n//2-2):
            fi+=dif2[i]
            if fi>0:
                if fi>ma:
                    ma=fi
            else:
                fi=0
        m2=su+ma
        print(max(m1,m2))
    else:
        su=0
        su+=lis[-1]
        dif1=[]
        for i in range(0,n-1,2):
            su+=lis[i]
            dif1.append(lis[i]-lis[i+1])
        mi = 0
        fi = 0
        for i in range(n // 2):
            fi += dif1[i]
            if fi < 0:
                if fi < mi:
                    mi = fi
            else:
                fi = 0
        m1 = su - (mi)
        dif2=[]
        for i in range(1,n,2):
            dif2.append(lis[i]-lis[i+1])
        ma = 0
        fi = 0
        for i in range(len(dif2)):
            fi += dif2[i]
            if fi > 0:
                if fi > ma:
                    ma = fi
            else:
                fi = 0
        m2 = su + ma
        print(max(m1, m2))
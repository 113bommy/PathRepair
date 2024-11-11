t=int(input())
for i in range(t):
    n,m = map(int,input().split())
    sp = list(map(int,input().split()))
    if m<n:
        print(-1)
    else:
        min1 = 100000
        min2 = 100000
        pos1 = 0
        pos2 = 0
        s = 0
        for i in range(n):
            s += sp[i]
            if sp[i]<min1:
                min1 = sp[i]
                pos1 = i+1
            elif sp[i]<min2 :
                min2 = sp[i]
                pos2 = i+1
        print(2*s + (m-n)*(min1+min2))
        for i in range(n-1):
            print(i+1,i+2)
        print(n,1)
        for i in range(m-n):
            print(pos1,pos2)
    

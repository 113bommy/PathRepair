for t in range(int(input())):
    L,v,l,r = list(map(int,input().split()))
    total = L//v
    q2 = r//v
    q1 = l//v if l%v==0 else l/v-1
    print(int(total-(q2-q1+1)))
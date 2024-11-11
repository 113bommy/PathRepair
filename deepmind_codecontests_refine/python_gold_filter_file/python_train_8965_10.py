q = int(input())
while(q):
    l1,r1,l2,r2 = map(int, input().split())
    a = 0
    b = 0
    if(l1==l2):
        a = l1
        b = l1+1
    else:
        a = l1
        b = l2
    print(a,b)
    q-=1
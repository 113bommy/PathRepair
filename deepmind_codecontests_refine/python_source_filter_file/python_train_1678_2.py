t=int(input())
for i in range (t):
    L,v,l,r=map(int,input().split())
    if (L-r)%v==0:
        print(int((l-1)/v)+int((L-r)/v))
    else:
        print(int((l-1)/v)+int((L-r+(l%v))/v))
    

for _ in range (int(input())):
    n=int(input())
    t=''
    ls=list(map(str,input().split()))
    t=t+ls[0][0]
    for i in range (n-3):
        if ls[i][1]==ls[i+1][0]:
            t+=ls[i][1]
        else:
            t+=ls[i][1]+ls[i+1][0]
    t+=ls[n-3][1]
    if len(t)<n:
        if 'a' not in t:
            t+='a'
        elif 'b' not in t:
            t='b'
        else:
            t+=ls[-1][1]
    if n==3:
        if 'b' not in ls[0]:
            t='baa'
        elif 'a' not in ls[0]:
            t='abb'
        else:
            t=ls[0]+ls[0][1]
    print(t)

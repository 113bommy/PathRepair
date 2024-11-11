def score(x):
    s=0;t=1
    for _ in[0]*10:
        a=2;b=3
        if x[t]==10:a=1
        elif x[t]+x[t+1]!=10:b=2
        s+=sum(x[t:t+b]);t+=a
    return x[0],s

while 1:
    n=int(input())
    if n==0:break
    A=sorted([score(list(map(int,input().split()))) for _ in [0]*n])
    for a,b in sorted(A,key=lambda x:-x[1]):print(a,b)
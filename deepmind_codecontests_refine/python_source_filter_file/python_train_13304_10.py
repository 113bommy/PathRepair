L,R=map(int,input().split())
if L-R>=2019:
    print(0)
else:
    x=[i*j%2019 for i in range(L,R) for j in range(i+1,R+1)]
    print(min(x))
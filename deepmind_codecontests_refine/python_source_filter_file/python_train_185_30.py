N,P = map(int,input().split())
r = round(P**(1/N))
for i in range(r,0,-1):
    if P%i==0:
        print(i)
        exit()
N,P = map(int,input().split())
c = int(P**(1/N))+1
for i in range(c,0,-1):
    if P%(i**N)==0:
        print(i)
        exit()
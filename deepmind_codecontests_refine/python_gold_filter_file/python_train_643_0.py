

# C. Shawarma Tent
# Link https://codeforces.com/contest/1271/problem/C

n,x,y = map(int,input().split(" "))

N = S = W = E = 0

for i in range(n):
    x1,y1 = map(int,input().split(" "))
    ydif = y1-y
    xdif = x1-x
    if(xdif < 0):
        W+=1
    if(xdif > 0):
        E+=1
    if(ydif < 0):
        S+=1
    if(ydif > 0):
        N+=1

if (N == max(N,S,W,E)):
    print(N)
    print(x,y+1)
elif (S == max(N,S,W,E)):
    print(S)
    print(x,y-1)
elif (E == max(N,S,W,E)):
    print(E)
    print(x+1,y)
elif (W == max(N,S,W,E)):
    print(W)
    print(x-1,y)

x,y = map(int,input().split())
for i in range(x+1):
    for j in range(x-i+1):
        if 10000*i+5000*j+1000*(x-i-j) == y:
            print(i,j,x-i-j)
            exit()
print("-1 -1 -1")
N,Y=map(int,input().split())

for a in range(N):
    for b in range(N-a):
        c=N-a-b
        if a*10000+b*5000+1000*c==Y:
            print(a,b,c)
            exit()
print('-1 -1 -1')

A,B=map(int,input().split())
for x in range(10*B,10*B+10):
    if A*100/8<=x<=A*100/8+100/8:
        print(x)
        exit()
print("-1")
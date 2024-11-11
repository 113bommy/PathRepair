l = list(map(int,input().split()))
if(sum(l) == 0):
    print(0)
elif(sum(l)%5 == 0):
    print(sum(l)//5)
else:
    print(-1)
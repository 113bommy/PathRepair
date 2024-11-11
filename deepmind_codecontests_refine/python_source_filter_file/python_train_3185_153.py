a,b=map(int,input().split())
i=1
while 1:
    i+=1
    if a*3**i>b*2**i:
        break
print(i)
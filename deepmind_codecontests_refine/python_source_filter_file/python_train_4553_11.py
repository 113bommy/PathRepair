n=int(input())
inp = list(map(int,input().split()))
k=sum(inp)/len(inp)
if(k>=4.5):
    print(0)
else:
    inp.sort()
    count=0
    for i in range(0,len(inp)):
        k=k+((5-inp[i])/len(inp))
        count=count+1
        if(k>=4.5):
            break
    print(count)
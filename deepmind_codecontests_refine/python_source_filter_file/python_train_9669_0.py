size = [60,80,100,120,140,160]        
weight = [2,5,10,16,20,25]
fee= [600,800,1000,1200,1400,1600]
while True:
    n = int(input())
    if n==0:
        break
    total = 0
    for _ in range(n):
        [x,y,h,wt] = list(map(int, input().strip().split()))
        sz = x+y+h
        if sz <= size[-1] and wt <= weight[-1]:
            isz = len(list(filter(lambda x: x<sz,   size)))
            iwt = len(list(filter(lambda x: x<wt, weight)))
            f   = fee[max(isz,iwt)]
            #print("%d %d %d %d %d" % (x,y,h,wt,f))
            total += f
    print(total)
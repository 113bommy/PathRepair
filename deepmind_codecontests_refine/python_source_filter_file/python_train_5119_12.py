n, M = map(int, input().split())
a = list(map(int, input().split()))
b = [0] * 110
 
 
for x in a:
    
    cc = 0
    cur = 0
    for j in range(1, 7):
        h = min((M-x-cur)//j, b[j])
        
        cc += h
        cur += h * j
        #print(h,cc,cur,(M-x-cur)//j,"  ",x)
    b[x] += 1
    #print()
    print(sum(b) - cc - 1)

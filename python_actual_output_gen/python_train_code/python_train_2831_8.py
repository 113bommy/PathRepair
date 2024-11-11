a = int(input())
for _ in range(a):
    x= int(input())
    li = list(map(int, input().split()))
    
    p = -1
    if x == 1: print(p)
    elif x== 2: print(li[0]^li[1])
    else:
        for i in range(1,1025):
            for j in li:
                if j^i not in li:
                    break
            else: p =i; break
    
    print(p)

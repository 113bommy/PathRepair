def solve(total,guest,segment):
    for index in range(total) :
        if index%2 == 0 :
            print (0,end = " ")
        else :
            print (1,end= " ")
    
total,guest = list(map(int,input().split()))
seg = []
for _ in range(guest) :
    seg.append(input().split())
solve(total,guest,seg)
    
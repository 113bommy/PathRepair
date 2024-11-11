def cars(v1,v2,v3,vm):
    if vm>2*v3:
        return -1
    if 2*vm>2*v2:
        return -1
    for i in range(2*v3,v3-1,-1):
        # print(i,vm)
        if vm<=i and 2*vm>=i:
            return 2*v1,2*v2,i
    return -1

v1,v2,v3,vm=list(map(int, input().split()))
assert(cars(50,30,10,10) == (100, 60, 20))
assert(cars(100,50,10,21) == -1)
# assert(cars(60,50,10,21) == '-1')
if cars(v1,v2,v3,vm)==-1:
    print(-1)
else:
    for i in cars(v1,v2,v3,vm):
        print(i)

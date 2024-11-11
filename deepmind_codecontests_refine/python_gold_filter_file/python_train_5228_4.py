testcase = int(input())
for i in range(testcase):
    a,b = list(map(int, input().split()))
    prothome_dimu = (a//b)*b
    baki = a - prothome_dimu
    half = b//2
    if baki >= half:
        total = (prothome_dimu) + half
        print(total)
    else:
        print(prothome_dimu+baki)

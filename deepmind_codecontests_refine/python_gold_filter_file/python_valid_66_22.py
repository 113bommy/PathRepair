p=int(input())
for i in range(p):
    n=int(input())
    k=0
    if n%18==0:
        k=int(n/18)-1
    else:
        k=int(n/18)
    k = k * 30
    r=n%18

    val=[1,2,4,5,7,8,10,11,14,16,17,19,20,22,25,26,28,29]
    print(k+val[r-1])
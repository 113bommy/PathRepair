N=int(input())
for i in range(1,3501):
    for j in range(i,3501):
        bw=4*i*j-N*i-N*j
        if bw<=0:
            continue
        if (N*i*j)%bw==0:
            print(i,j,(N*i*j)//bw)
            exit()
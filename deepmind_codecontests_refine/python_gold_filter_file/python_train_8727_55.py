n = int(input())

for i in range(1,3501):
    for j in range(1,3501):
        if (4*i*j-n*i-n*j) != 0:
            w = i*j*n/(4*i*j-n*i-n*j)
            if w%1 == 0 and w > 0:
                print(i,j,int(w))
                exit()
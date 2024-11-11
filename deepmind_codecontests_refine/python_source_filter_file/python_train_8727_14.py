n=int(input())

for i in range(1,3501):
    for j in range(j,3501):
        if 4*i*j-n*i-n*j>0 and n*i*j%(4*i*j-n*i-n*j)==0:
            w=n*i*j//(4*i*j-n*i-n*j)
            print(i,j,w)
            quit()
        else:
            continue
s=int(input())
for i in range(s//4,3501):
    for j in range(1,3501):
        t=4*i*j-i*s-j*s
        y=s*i*j
        if t>0 and s*i*j%t==0:
            print(s*i*j//t,i,j)
            exit()

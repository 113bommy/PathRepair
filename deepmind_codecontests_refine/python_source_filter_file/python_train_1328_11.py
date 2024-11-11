#code
N,M = input().split()
N=int(N)
M=int(M)
p=max(N,M)
ans=((6-p)+1)
if ans==0:
    print("{}/{}".format(0,1))
elif ans==1:        
    print("{}/{}".format(1,1))
elif ans==2:        
    print("{}/{}".format(1,3))
elif ans==3:
    print("{}/{}".format(1,2))
elif ans==4:
    print("{}/{}".format(2,3))
elif ans==5:
    print("{}/{}".format(5,6))
else:
    print("{}/{}".format(1,1))
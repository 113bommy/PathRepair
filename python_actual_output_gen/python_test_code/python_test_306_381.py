line1 = input()
M = (int)(line1.split(" ")[0])
N = (int)(line1.split(" ")[1])

if((M*N)%2==0 or (M*N)%2==1):
    print(int(M*N)/2)

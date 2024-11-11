for u in range(int(input())):
    n=int(input())
    z=n//5
    r=n%5
    if(n==1 or n==2 or n==4):
        print(-1)
    elif(r==4):
        print(3,z,0)
    elif(r==1):
            print(2,z-1,0)
    elif(r==2):
        print(0,z-1,1)
    elif(r==3):
        print(1,z,0)
    elif(r==0):
        print(0,z,0)

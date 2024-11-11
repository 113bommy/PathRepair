for i in range (int(input())):
    a,b=map(int,input().split())
    s=0
    for k in range (2,a+1):
            if a%k==0:
                s=k
                break
    print(a+s+(2*(b-1)))
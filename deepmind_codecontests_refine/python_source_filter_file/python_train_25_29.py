#import datetime

t=int(input())
for _ in range(t):
    n=int(input())
    l=[None]*n
    for i in range(n):
        l[i]=list(input().split())
    if(int(l[n-1][0][n-2]) ^ int(l[n-2][0][n-1])):
        if(int(l[0][0][1]) ^ int(l[1][0][0])):
            print(2)
            if(int(l[n-1][0][n-2]) ^ int(l[0][0][1])):
                print(str(n)+" "+str(n-1))
                print(str(1)+" "+str(2))
            else:
                print(str(n)+" "+str(n-1))
                print(str(2)+" "+str(1))

        else:
            print(1)
            if(int(l[1][0][0]) ^ int(l[n-1][0][n-2])):
                print(str(n-1)+" "+str(n))
            else:
                print(str(n)+" "+str(n-1))


    else:
        if(int(l[0][0][1]) ^ int(l[1][0][0])):
            print(1)
            if(int(l[n-1][0][n-2]) ^ int(l[1][0][0])):
                print(str(2)+" "+str(1))
            else:
                print(str(1)+" "+str(2))

        else:
            if(int(l[0][0][1]) ^ int(l[n-1][0][n-2])):
                print(0)
            else:
                print(2)
                print(str(1)+" "+str(2))
                print(str(2)+" "+str(1))

'''be=datetime.datetime.now()


e=datetime.datetime.now()

print(e-be)




S10
000
01F'''

n=int(input())
l=[]
for i in range(n):
    l1,l2=input().split()
    l.append([int(l1),int(l2)])

if(n<=1):
    print(-1)
else:
    if(n==2):
        if(l[0][0]==l[1][0] or l[0][1]==l[1][1]):
            print(-1)
        else:
            print(abs(l[0][0]-l[1][0])*abs(l[0][1]-l[1][1]))
    else:
        print(abs(l[0][0]*(l[1][1]-l[2][1])+l[1][0]*(l[1][1]-l[0][1])+l[2][1]*(l[0][1]-l[1][1])))

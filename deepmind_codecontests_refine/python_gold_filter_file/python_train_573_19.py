#from dust i have come, dust i will be

a,b,c=map(int,input().split())

for i in range(0,1000):
    x=c-(i*a)

    if(x<0):
        break

    if x%b==0:
        print("YES")
        exit(0)

print("NO")


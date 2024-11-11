def sumn (n):
    tot=0
    while(n>0):
        dig=n%10
        tot=tot+dig
        n=n//10
    return (tot)
n=int(input())

for i in range (0,5):
    if (sumn(i+n)%4==0):
        print(i+n)
        break
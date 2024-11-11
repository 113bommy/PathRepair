t=int(input())
i=1
l=[]
while (i<=t):
    x = int(input())
    l.append(x)
    i+=1
for n in l:
    if (n==1):
        print (1)
    elif ((n//2)!=0):
        n=n-1
        print(n//2)
    else:
        print(n // 2)

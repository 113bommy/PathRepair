n=int(input())

l=list(map(int,input().split()))

a=1


while True:
    n-=l[a-1]
    if(n<=0):
        print(a)
        break
    else:
        a+=1
        if(a>7):
            a=a%7
        

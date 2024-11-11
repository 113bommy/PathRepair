t= int(input())

for _ in range (0,t):

    n,x= map(int,input().split())

    maxx=0

    diff=0
    for i in range (0,n):

        d,h= map(int,input().split())

        maxx=max(maxx,d)
        diff = max(diff,d-h)

    #print("maxx ",maxx,"diff ",diff) 


    if x<= maxx:
        print(1)
    elif diff>0:
        modd= x%diff

        ans=((x)//diff)
       # print(ans,"before")
      #  print("modd ",modd,"ans ",ans)
        ans = ans - ((((maxx-modd))//diff) ) +1 
       # ans= max(ans,-1)
        print(ans)

    else:
        print(-1)

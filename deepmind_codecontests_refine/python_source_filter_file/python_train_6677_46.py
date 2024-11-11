for i in range(int(input())):
          s=0
          nab=list(map(int,input().strip().split()))
          n=nab[0]
          a=nab[1]
          b=nab[2]
          if(n==1):
                    print(a)
          elif((a*2)<=b):
                    print(n*a)
          else:
                    if(n%2==0):
                              print((n/2)*b)
                    else:
                              s=int(n/2)
                              print((s*b)+a)
                

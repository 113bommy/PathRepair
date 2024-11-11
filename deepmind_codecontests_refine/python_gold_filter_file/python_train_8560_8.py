import math

if __name__== '__main__':
    
    testCases= int(input())

    for _ in range(testCases):

        x, n, m = map(int,input().split())
        
        while((n> 0) or (m> 0)):

            if(x> 20):

                if(n> 0):
                    x= x// 2+ 10
                    n-= 1
                else:
                    x-= 10
                    m-= 1
            else:
                if(m> 0):
                    x-= 10
                    m-= 1
                else:
                    x= x// 2+ 10
                    n-= 1
            
            #print('x: '+str(x)+' n: '+str(n)+' m: '+str(m))

            if(x< 1):
                break

        if(x< 1):
            print('YES')
        else:
            print('NO')

            



        
            
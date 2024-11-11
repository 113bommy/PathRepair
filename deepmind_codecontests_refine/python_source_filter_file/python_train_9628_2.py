def M(a,b,k):
    
    c=1
    
    if(b>k):
        print(k)
    else:
        print("YES")
        for i in range(a):
            for x in range(a):
                if(i%2==0):
                    
                    if(x%2==0 and c<=b):
                        print("L", end='')
                        c+=1
                    else:
                        print("S", end='')
                else:
                     
                    if(x%2==1 and c<=b):
                        print("L", end='')
                        c+=1
                    else:
                        print("S", end='')
                    
            print()
    
if __name__=='__main__':
    a,b=map(int,input().split())
    if(a%2==0):
        k=(a/3)*a
    else:
        n=(a//2)+1
        m=(a//2)
        k=(n*n)+(m*m)
    M(a,b,k)
    
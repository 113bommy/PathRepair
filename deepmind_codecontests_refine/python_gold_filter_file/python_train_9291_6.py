def solu(n,k):
    r = 2 if k%n else 0
    a = cr_matrix(n,0)
    remain = k
    if(k==0):
        return (r,a)
    i,j = 0,0
    d = 1
    
    while remain>0:
        a[i][j] = 1
        
        remain -= 1
        if(j==n-1 and i == n-1):
            i = 0
            j = 1
     
        elif(j==n-1):
            i +=1
            j = 0
       
        elif(i==n-1):
            i = 0
            j+=2
    
        else:
            i+=d
            j+=d
    return (r,a)

def cr_matrix(n,p):
    matrix = [([p]*n) for i in range(n)]
    return matrix

nt = int(input())
for i in range(nt):
    test = input().split(" ")
    n = int(test[0])
    k = int(test[1])
    result = solu(n,k)
    print(result[0])
    for r in range(n):
        row = "".join(str(v) for v in result[1][r])
        print(row)
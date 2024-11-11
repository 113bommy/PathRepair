t = int(input())
while t>0:
    n, k = [int(ele) for ele in input().split()]
    matrix = [[0 for i in range(n)] for j in range(n)]
    if k<n:
        i = 0
        if k == 0:
            print(0)
        else:
            print(2)
        for i in range(k):
            matrix[i][i] = 1 
        for i in range(n):
            for j in range(n):
                print(matrix[i][j], end = "")
            print()
        
    else:
        if k == n*n:
            print(0)
            for i in range(n):
                for j in range(n):
                    print(1, end = "")
                print()
        else:
            div = k//n 
            index = 0
            for i in range(n):
                j = index%n 
                x = div
                while(x>0):
                    if j != index:
                        matrix[i][j] = 1
                        x -= 1
                    j = (j+1)%n
                    
                index += 1 
            
            rem = k%n
            if rem == 0:
                print(0)
            else:
                print(2)
                index = 0
                while(rem > 0):
                    matrix[index][index] = 1 
                    index += 1 
                    rem -= 1 
        
            for i in range(n):
                for j in range(n):
                    print(matrix[i][j], end = "")
                print()
    t -= 1
    
                
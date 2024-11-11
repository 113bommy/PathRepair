def solve():
    n,m=[int(x) for x in input().split()]
    matrix = [None for _ in range(n)]
    for i in range(n):
        matrix[i] = input()
    
    fine,white_row=True,0
    for i in range(n):      
        white_count=0
        found_black,found_white=False,False       
        for j in range(m):
            if matrix[i][j]=='#' and found_black==True and found_white==True:
                fine=False
                break   
            elif matrix[i][j]=='#' and found_black==False:
                found_black=True
            elif matrix[i][j]=='.':
                white_count+=1  
                if found_black==True:
                    found_white=True
        if fine==False:
            
            print(-1)
            return
        if white_count==m:
            white_row+=1
    
    fine,white_col=True,0
    for j in range(m):      
        white_count=0
        found_black,found_white=False,False
        for i in range(n):
            if matrix[i][j]=='#' and found_black==True and found_white==True:
                fine=False
                break
            elif matrix[i][j]=='#' and found_black==False:
                found_black=True   
            elif matrix[i][j]=='.':
                white_count+=1
                if found_black==True:
                    found_white=True
                
                
        if fine==False:
            
            print(-1)
            return
        if white_count==n:
            white_col+=1
                         
    if (white_row>0 or white_col>0) and white_row==n:
        print(0)
        return
    
    if (white_row!=0 and white_col==0) or (white_col!=0 and white_row==0):
        
        print(-1)
        return
                         
    comp=0
    for j in range(m):
        if matrix[0][j]=='#':
            comp+=1
            break
                         
    for i in range(1,n):
        black_found=True
        connected=False
        for j in range(m):
            if matrix[i][j]=='#':
                black_found=True
                if matrix[i-1][j]=='#':
                    connected=True
                    break
        if black_found and not(connected):
            comp+=1
    print(comp)
    return               
                         
solve()
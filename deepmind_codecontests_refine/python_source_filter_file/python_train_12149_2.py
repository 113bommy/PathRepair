n,m=map(int, input().split())
ar=[[i for i in input()] for j in range(n)]
def bombva(arr):
    if n>=2 and m>=2:
        if arr[0][0]!='*':
            c=0
            if arr[0][1]=='*': c+=1
            if arr[1][0]=='*': c+=1
            if arr[1][1]=='*': c+=1
            if (c==0 and arr[0][0]!='.') or (c!=0 and arr[0][0]!=str(c)):
                return('NO')
                
        if arr[0][m-1]!='*':
            c=0
            if arr[0][m-2]=='*': c+=1
            if arr[1][m-1]=='*': c+=1
            if arr[1][m-2]=='*': c+=1
            if (c==0 and arr[0][m-1]!='.') or (c!=0 and arr[0][m-1]!=str(c)):
                return('NO')
        if arr[n-1][0]!='*':
            c=0
            if arr[n-1][1]=='*': c+=1
            if arr[n-2][0]=='*': c+=1
            if arr[n-2][1]=='*': c+=1
            if (c==0 and arr[n-1][0]!='.') or (c!=0 and arr[n-1][0]!=str(c)):
                return('NO')
        if arr[n-1][m-1]!='*':
            c=0
            if arr[n-1][m-2]=='*': c+=1
            if arr[n-2][m-1]=='*': c+=1
            if arr[n-2][m-2]=='*': c+=1
            if (c==0 and arr[n-1][m-1]!='.') or (c!=0 and arr[n-1][m-1]!=str(c)):
                return('NO')
        
        
        for i in range(1,n-1):
            if arr[i][0]!='*':
                c=0
                if arr[i][1]=='*': c+=1
                if arr[i-1][0]=='*': c+=1
                if arr[i-1][1]=='*': c+=1
                if arr[i+1][0]=='*': c+=1
                if arr[i+1][1]=='*': c+=1
                if (c==0 and arr[i][0]!='.') or (c!=0 and arr[i][0]!=str(c)):
                    return('NO')
                    
            if arr[i][m-1]!='*':
                c=0
                if arr[i][m-2]=='*': c+=1
                if arr[i-1][m-2]=='*': c+=1
                if arr[i-1][m-1]=='*': c+=1
                if arr[i+1][m-2]=='*': c+=1
                if arr[i+1][m-1]=='*': c+=1
                if (c==0 and arr[i][m-1]!='.') or (c!=0 and arr[i][m-1]!=str(c)):
                    return('NO')
                
        for j in range(1,m-1):
            if arr[0][j]!='*':
                c=0
                if arr[1][j]=='*': c+=1
                if arr[0][j+1]=='*': c+=1
                if arr[1][j+1]=='*': c+=1
                if arr[0][j-1]=='*': c+=1
                if arr[1][j-1]=='*': c+=1
                if (c==0 and arr[0][j]!='.') or (c!=0 and arr[0][j]!=str(c)):
                    return('NO')
            if arr[n-1][j]!='*':
                c=0
                if arr[n-2][j]=='*': c+=1
                if arr[n-1][j+1]=='*': c+=1
                if arr[n-2][j+1]=='*': c+=1
                if arr[n-1][j-1]=='*': c+=1
                if arr[n-2][j-1]=='*': c+=1
                if (c==0 and arr[n-1][j]!='.') or (c!=0 and arr[n-1][j]!=str(c)):
                    return('NO') 
            
                
        for i in range(1,n-1):
            for j in range(1,m-1):
                if arr[i][j]!='*':
                    c=0
                    if arr[i][j+1]=='*': c+=1
                    if arr[i][j-1]=='*': c+=1
                    if arr[i-1][j]=='*': c+=1
                    if arr[i-1][j+1]=='*': c+=1
                    if arr[i-1][j-1]=='*':c+=1
                    if arr[i+1][j]=='*': c+=1
                    if arr[i+1][j+1]=='*': c+=1
                    if arr[i+1][j-1]=='*': c+=1
                    if (c==0 and arr[i][j]!='.') or (c!=0 and arr[i][j]!=str(c)):
                        return('NO')
        return('YES')
    elif n==1 and m>=2:
        if arr[0][0]!='*':
            if (arr[0][1]=='*' and arr[0][1]!='1') or (arr[0][1]!='*' and arr[0][1]!='.'):
                return('NO')
        if arr[0][m-1]!='*':
            if (arr[0][m-2]=='*' and arr[0][m-1]!='1') or (arr[0][m-2]!='*' and arr[0][m-1]!='.'):
                return('NO')
        for j in range(1,m-1):
            if arr[0][j]!='*':
                c=0
                if arr[0][j-1]=='*': c+=1
                if arr[0][j+1]=='*': c+=1
                if (c==0 and arr[0][j]!='.') or (c!=0 and arr[0][j]!=str(c)):
                    return('NO')
        return('YES')
        
    elif m==1 and n>=2:
        if arr[0][0]!='*':
            if (arr[1][0]=='*' and arr[0][0]!='1') or (arr[1][0]!='*' and arr[0][0]!='.'):
                return('NO')
        if arr[n-1][0]!='*':
            if (arr[n-2][0]=='*' and arr[n-1][0]!='1') or (arr[n-2][0]!='*' and arr[n-1][0]!='.'):
                return('NO')
        for i in range(1,n-1):
            if arr[i][0]!='*':
                c=0
                if arr[i-1][0]=='*': c+=1
                if arr[i+1][0]=='*': c+=1
                if (c==0 and arr[i][0]!='.') or (c!=0 and arr[i][0]!=str(c)):
                    return('NO')
        return('YES')
    if arr[0][0] in '.*': return('YES')
    return('NO')
print(bombva(ar))
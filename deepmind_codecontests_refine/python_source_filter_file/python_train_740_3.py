from collections import defaultdict
n = int(input())
arr = list(map(int,input().split()))
counts = defaultdict(int)
for a in arr: counts[a]+=1

if n==1:
    print('YES')
    print(arr[0])
    exit(0)
    
matrix = [ [None]*n for _ in range(n)]
if n%2==0:
    vals= []
    for val,cnt in counts.items():
        if cnt%4!=0:
            print('NO')
            exit(0)
        vals.append( (val,cnt) )

    for i in range(n//2):
        for j in range(n//2):
            val,cnt = vals.pop(0)
            matrix[i][j] = val
            matrix[i][n-j-1] = val
            matrix[n-i-1][j] = val
            matrix[n-i-1][n-j-1] = val
            if cnt-4 != 0:
                vals.append( (val,cnt-4) )
    print('YES')
    for row in matrix: print(*row)
else:
    vals = []
    avail=True
    c = 0
    for val,cnt in counts.items():
        if cnt%4==1 and avail:
            avail=False
            matrix[(n//2)][(n//2)] = val
            cnt-=1
            if cnt!=0: vals.append( (val,cnt) )
        elif cnt%4==3 and avail:
            avail = False
            matrix[(n//2)][(n//2)] = val
            if c <  n//2:
                matrix[ n//2 ][c] = val
                matrix[ n//2 ][ n-c-1 ] = val
                c+=1
            elif c < n-1:
                i = c%(n//2)
                matrix[ i ][n//2] = val
                matrix[n-i-1][n//2] = val
                c+=1
            else:
                print('NO');exit(0)
            if (cnt-3) > 0 :
                vals.append( (val,cnt-2) )
                
        elif cnt%4==0:
            vals.append( (val,cnt) )
        elif cnt%2==0:
            if c <  n//2:
                matrix[ n//2 ][c] = val
                matrix[ n//2 ][ n-c-1 ] = val
                c+=1
            elif c < n-1:
                i = c%(n//2)
                matrix[ i ][n//2] = val
                matrix[n-i-1][n//2] = val
                c+=1
            else:
                print('NO');exit(0)
            
            if (cnt-2) > 0 :
                vals.append( (val,cnt-2) )
        else:
            print('NO');exit(0)
            
    while c<n-1:
        val,cnt = vals.pop(0)
        if c < n//2:
            matrix[ n//2 ][c] = val
            matrix[ n//2][ n-c-1 ] = val
            c+=1
        else:
            i = c%(n//2)
            matrix[ i ][n//2] = val
            matrix[n-i-1][n//2] = val
            c+=1
        
        if cnt-2 > 0:
            vals.insert(0,(val,cnt-2))
    
    if vals[0][1] % 4 !=0: print('NO');exit(0)
        
    if avail: print('NO'); exit(0)
    for i in range( n//2):
        for j in range( n//2):
            val,cnt = vals.pop(0)
            matrix[i][j] = val
            matrix[i][n-j-1] = val
            matrix[n-i-1][j] = val
            matrix[n-i-1][n-j-1] = val
            if cnt-4 != 0:
                vals.append( (val,cnt-4) )
    print('YES')
    for row in matrix: print(*row)
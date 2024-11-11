def main():
    for _ in range(int(input())):
        n = int(input())
        s = input()
        
        ans = []
        for i in range(1,n):
            if s[i] == 'L' and s[i - 1] == 'R':
                ans = [i, i + 1]
                break
            if s[i] == 'R' and s[i - 1] == 'L':
                ans = [i, i + 1]
                break
            if s[i] == 'U' and s[i - 1] == 'D':
                ans = [i, i + 1]
                break
            if s[i] == 'D' and s[i - 1] == 'U':
                ans = [i, i + 1]
                break
            
        if not ans:
            ok = ['LURD', 'LDRU', 'RULD', 'RDUL', 'DLUR', 'DRUL', 'URDL', 'ULDR']
            for i in range(4,n + 1):
                if s[i - 4:i] in ok:
                    ans = [i - 3, i]
                    break
            if not ans:
                '''x = [0, 0]
                X = []
                X.append(x.copy())
                #X = { '00':0 }
                L = n + 1
                for i in range(n):
                    if s[i] == 'U':
                        x[1] += 1
                    if s[i] == 'R':
                        x[0] += 1
                    if s[i] == 'D':
                        x[1] -= 1 
                    if s[i] == 'L':
                        x[0] -= 1
                    
                    #p = str(x[0]) + str(x[1])
                    if x in X:
                        f = X.index(x)
                        #f = X[p]
                        if i - f < L:
                            ans = [f + 1, i + 1]
                            L = i - f
                        #X[p] = i
                    X.append(x.copy())
                    #else:
                       # X[p] = i
                
                      '''
                L = n + 1
                p = (0, 0)
                d = {p:1}
                x, y = 0, 0          
                for j in range(n):
                    if s[j] == 'U':
                        y += 1
                    if s[j] == 'R':
                        x += 1
                    if s[j] == 'D':
                        y -= 1 
                    if s[j] == 'L':
                        x -= 1
                        
                    if (x, y) in d:
                        #print(x, y)
                        #print(d)
                        if j - d[(x, y)] < L:
                            ans = [d[(x, y)], j + 1]
                            L = j - d[(x, y)]
                    d[(x, y)] = j + 2
                                
                        
              
            
        if ans:
            print(*ans)
        else:
            print(-1)
            
            
            
    
main()













'''ok = ['LURD', 'LDRU', 'RULD', 'RDUL', 'DLUR', 'DRUL', 'URDL', 'ULDR']
for i in range(4,n):
    print(s[i - 4:i])
    if s[i - 4:i] in ok:
        ans = [i - 3, i]
        break'''
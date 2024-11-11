n = int(input())
m = []
r = 0
c = True
s = 0

for i in range(n):
    m.append([int(x) for x in input().split()])

if n > 1:    
    for i in range(n):
        found = False
        for j in range(n):
            if m[i][j] == 0:
                if i == n - 1:
                    m[i][j] = sum(m[i-1]) - sum(m[i])
                else:
                    m[i][j] = sum(m[i+1]) - sum(m[i]) 
                
                r = m[i][j]
                found = True
                break
        
        if found:
            break
else:
    m[0][0] = 1
    r = m[0][0]
    
s = sum(m[0])
if c == True:
    for i in range(1,n):
        if sum(m[i]) != s:
            c = False
            break
    
mt = list(map(list, zip(*m)))
if c == True:
    for i in range(n):
        if sum(mt[i]) != s:
            c = False
            break
        
if c == True:
    st = 0
    for i in range(n):
        st += m[i][i]
    if st != s:
        c = False
        
if c == True:
    st = 0
    for i in range(n):
        st += m[i][n-1-i]
    if st != s:
        c = False

if c == False and r == 0:
    r = -1
    
print(r)
n_m_k = input().split()
n = int(n_m_k[0])
m = int(n_m_k[1])
k = int(n_m_k[2])

msv = [[0 for i in range(m)] for j in range(n)] 
c = 1
vivod = k + 1

while c <= k:
    vvod = input().split()
    i = int(vvod[0]) - 1
    j = int(vvod[1]) - 1
    msv[i][j] = 1

    if i - 1 > -1  and j + 1 < m:
        if msv[i-1][j] == 1 and msv[i-1][j+1] == 1 and msv[i][j+1] == 1:
            if c < vivod:
                vivod = c
            

    if i + 1 < n and j + 1 < m:
        if msv[i+1][j] == 1 and msv[i+1][j+1] == 1 and msv[i][j+1] == 1:
            if c < vivod:
                vivod = c
            

    if i + 1 < n and j - 1 > -1:
        if msv[i+1][j-1] == 1 and msv[i+1][j] == 1 and msv[i][j-1] == 1:
            if c < vivod:
                vivod = c
            

    if i - 1 < n and j - 1 > -1:
        if msv[i-1][j-1] == 1 and msv[i-1][j-1] == 1 and msv[i][j-1] == 1:
            if c < vivod:
                vivod = c  
    c += 1
    
if vivod == k + 1:
    vivod = 0
    
print(vivod)
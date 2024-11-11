R = lambda : map(int, input().split() ) 
n, m = R() 
color = [0]*(n) 
for i in range(m):    
    d = list(R())
    temp =0 
    for j in  d :
        if color[j-1] != 0 :
            temp  = temp | ( 1 << color[j] ) 
    for j in d : 
        if  color[j-1] == 0 : 
            for k in range(3):
                if not ( (1 << (k+1) ) &  temp ) :
                    color[j-1] = k+1 
                    temp  = temp | ( 1 << k+1 ) 
                    break 
print(' '.join(map(str, color)) )

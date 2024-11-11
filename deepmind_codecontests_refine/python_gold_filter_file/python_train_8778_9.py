n, m = map(int, input().split())
data = []
for i in range(0,m):
    ai, bi = map(int, input().split())
    data.append([ai, bi])
     
data.sort(key = lambda row: row[1], reverse = True)    
#print("sorted data")
#print(data)

space = n
total_matches = 0
for i in range(0,m):
    if data[i][0] < space:
        space = space - data[i][0]
        total_matches += data[i][0]*data[i][1]
        #print("matches collected:", total_matches) 
        #print("space left:", space)
    elif space>0:
        total_matches += space * data[i][1]
        space = 0      
        #print("matches collected*:", total_matches)
        #print("space left*:", space)
    
    
    

print(total_matches)        
        
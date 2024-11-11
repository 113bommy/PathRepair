ref = {"Q":9,"R":5,"B":3,"K":3,"P":1}
white = 0
black = 0
for x in range (8):
    ch = list(input())
    filtered = [y for y in ch if y.upper() in ref.keys()]
    for y in filtered :
        if y not in ref.keys():
            black += ref[y.upper()]
        else:
            white += ref[y]

if (white == black):
    print ("Draw")
elif (white > black):
    print ("White")
else:
    print ("Black")
        
        
        
    
    
    
        
    

        
    
        

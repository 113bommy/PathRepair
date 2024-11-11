"""
a=1
b=1
c=10000
"""

a, b, c = tuple(map(int, input().split()))

if a == c:
    print ("yes")
else:    
    if b == c:
        print ("yes")
        
    else:
        p1 = [x for x in range(c+1) if x % a == 0]
        if c in p1:
            print ("yes")            
        else:
             p2 = [y for y in range(c+1) if y % b == 0]
             if c in p2:
                 print ("yes")
             else:
                 shot = (r+s for r in p1 for s in p2 if r+s <= c and r+s > c-a-b)
                                   
                 if c in shot:                     
                     print ("yes")
                 else:
                     print ('no')

       

#print (shot)

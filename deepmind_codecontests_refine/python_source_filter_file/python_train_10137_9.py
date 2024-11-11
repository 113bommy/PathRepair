import math
for m in range(1,2):
    
    #n,L= list(map(int, input().split()))
    n = int(input())
    s = str(input())
    new=""
    i=0
    if n%2==0:
        for b in range((n//2)):
            print(b)
            
            new+= s[i:i+2] 
            new+="-"
            i+=2
            #print(b)
        print(new[0:len(new)-1])
    else:
        for b in range((n//2)+1):
            if i==0:
                new+=s[i:i+3] + "-"
                i+=3
                continue 
            print(i)
            new+= s[i:i+2] 
            new+="-"
            i+=2
       
        print(new[0:len(new)-2])
   # print(new)
            
  #  print(type(s))
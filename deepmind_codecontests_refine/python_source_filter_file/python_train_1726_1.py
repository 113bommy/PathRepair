def myf(n,L,mass1,mass2):


    if (n == 1):
        return 'YES'
    else:
        dist1 = [0 for i in range(n)]
        dist2 = [0 for i in range(n)]

        for i in range(n-1):
            dist1[i] = mass1[i+1] - mass1[i]
        dist1[-1] = mass1[0] + 8 - mass1[n-1] 

        #print (dist1)
        
        for i in range(n-1):
            dist2[i] = mass2[i+1] - mass2[i]
        dist2[-1] = mass2[0] + 8 - mass2[n-1]
        
        
        
        for each in range(n):
            #print (dist2)
            if (dist1 == dist2):
                return 'YES'
            else:
                c = dist2[-1]
                dist2.pop()
                dist2.insert(0, c)
                
        return "NO"
            
n,L  = map(int, input().split())
mass1 = list(map(int, input().split()))
mass2 = list(map(int, input().split()))
print (myf(n,L,mass1,mass2))
n = int(input())
sq = int(n**(1/2))
for i in range(sq,0,-1):
    if n%i==0:
        print(i,end=" ")
        print(n//i)
        exit()
    
    

t = int(input())
for i in range(t):
    l = [int(i) for i in input().split()]
    n = l[0];x = l[1]
    a = [int(i) for i in input().split()]
    o = [i for i in a if i%2 !=0 ]
    lo = len(o)
    if lo==0:
        print("No")
    if n==x :
        if lo%2==0:
            print("NO")
        else:
            print("yes")
    elif lo==n:
        if x%2==0:
            print("no")
        else:
            print("yes")
    else:
        if lo>1:
            print("yes")
        else:
            print("no")                
                    

            
    

        


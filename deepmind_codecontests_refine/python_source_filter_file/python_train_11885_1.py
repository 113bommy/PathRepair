n , m  = map(int , input().split())
fl1 = 0
A = []
B = []
for i in range(m):
    if i != 0:
        x1 , y1 = map(int , input().split())
        if x1 != x and y1 != x:
            A.append([x1 , y1])
        if x1 != y and y1 != y:
            B.append([x1 , y1])
        
            
    else:
        x , y  = map(int , input().split())
if len(A) != 0:
    x  = A[0][0]
    y  = A[0][1]
    flx = fly = 0
    for i in range(1 , len(A)):
        if A[i][1] != x and A[i][0] != x:
            flx =1
        if A[i][1] != y and A[i][0] != y:
            fly =1
    # print(A)
    if flx == 0 or fly ==0:
        print("YES" , 8)
    else:
        if len(B) != 0:
            x  = B[0][0]
            y  = B[0][1]
            flx = fly = 0
            for i in range(1 , len(B)):
                if B[i][1] != x and B[i][0] != x:
                    flx =1
                if B[i][1] != y and B[i][0] != y:
                    fly =1
            if flx == 0 or fly ==0:
                print("YES")
            else:
                print("NO")
        else:
            print("YES")
else:
    print("YES")
            
        

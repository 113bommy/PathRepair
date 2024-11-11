#code
#print("GfG")
t=int(input())
for _ in range(t):
    A,B = map(int,input().split())
    B+=1
    x=len(str(B))-1
    
                
    print(A*x)
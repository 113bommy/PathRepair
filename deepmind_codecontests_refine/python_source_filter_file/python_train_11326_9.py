H,W,A,B=map(int,input().split()
for i in range(B):
            print("0"*A +"1"*(W-A))
for i in range(H-B):
            print("1"*A +"0"*(W-A))

n,m=map(int,input().split())
output=[1]*n 
Xor=0
lis=[]
for i in range(n):
    lis2=list(map(int,input().split()))
    Xor=Xor^lis2[0]
    lis.append(lis2)
if Xor!=0:
    print("TAK")
    for i in output:
        print(i,end=" ")
    exit()
        
for i in range(n):
    element=lis[i][0]
    for j in range(1,m):
        if lis[i][j]!=element:
            output[i]=j+1
            print("TAK")
            for i in output:
                print(i,end=" ")
            
            exit()
print("NIE")
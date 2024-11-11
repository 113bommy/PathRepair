N,M=map(int,input().split())
D=list(map(int,input().split()))
a=N
b=0
for i in range(N,10001):
    for j in range(len(D)):
        if str(D[j]) in str(i):
            break  
    else:
        
        break
print(i)
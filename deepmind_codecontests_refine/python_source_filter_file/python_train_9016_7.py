n,k,m = map(int,input().split())
A = input().split()
B = [[] for x in range(0,m)] 
for i in range(0,len(A)):
    x = int(A[i])
    B[x%m].append(x)
    if len(B[x%m])==k:
        print("YES")
        print(" ".join(map(str, B[x%m])))
        exit()
print("NO")
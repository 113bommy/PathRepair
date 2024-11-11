n=int(input())
A=[int(i) for i in input().split()]
A.sort()
for i in range(1,n-1):
    if A[i-1]+A[i]>=A[i+1]:
        print("YES")
        break
else:
    print("NO")
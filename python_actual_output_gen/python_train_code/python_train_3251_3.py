n=int(input())
A=[int(i) for i in input().split()]
A.sort()
for i in range(n-2):
    if A[i]+A[i+1]>=A[i+2]:
        print("YES")
        break
else:
    print("NO")
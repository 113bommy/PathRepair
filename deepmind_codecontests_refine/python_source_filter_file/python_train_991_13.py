n=int(input())
A = list(map(int, input().split()))
g=0
A.append(0)
A.append(90)
A.sort()
print(A)
for i in range(len(A)-1):
    if (A[i+1]-A[i])>15:
        print(A[i]+15)
        g=10000
        break
if g==0:
    print(90)
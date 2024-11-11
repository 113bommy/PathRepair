n = int(input())
A = [int(a) for a in input().split()]
 
m = max(A)
D = [0] * n
for i in range(n):
    D[i] = m - A[i]
     
flag = False
D = set(D)
l = len(D)
if l <= 2:
    flag = True
elif l == 3:
    D = list(D)
    D.sort()
    a, b, c = D[0], D[1], D[2]
    flag = D[0] + D[2] == 2 * D[1]
     
print("YES" if flag else "NO")
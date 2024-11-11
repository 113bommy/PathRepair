n = int(input())
s = [int(x) for x in input().split()]
B = [1 for x in range(n//2)]
for i in range(1,len(B)):
    B[i] = B[i-1] + 2
W = [2 for x in range(n//2)]
for i in range(1,len(W)):
    W[i] = W[i-1] + 2
s1 = 0
s2 = 0
k = 0
for elem in B:
    s1+= abs(elem-s[k])
    k+=1
k = 0
for elem in W:
    s2+= abs(elem-s[k])
    k+=1
print(min(s1,s2))
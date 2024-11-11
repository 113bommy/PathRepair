n=int(input())
w=[int(i) for i in input().split()]
a=[]
for i in range(n-1):
    a.append(abs(sum(w[:i])-sum(w[i:])))
print(min(a))   
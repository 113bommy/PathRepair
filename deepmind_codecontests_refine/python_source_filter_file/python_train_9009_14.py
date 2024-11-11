n=int(input())
a = []
for _ in range(n):
    a.append(int(input()))
    
a = sorted(a)
b = sorted(a, reverse=True)
print (sum([i*j for i,j in zip(a,b)]))
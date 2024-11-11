n  = int(input())
t = list()
for i in range(n):
    a,b = map(int,input().split())
    t.append(a)
    t.append(b)
    
s = int(input())
for i in range(len(t)):
    if s<=t[i]:
        k=i
        break
print(n-k//n)
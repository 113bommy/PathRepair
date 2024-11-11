n = int(input())
s=0
m=0
for i in range(n):
    a = [ int(i) for i in input().split() ]
    s = sum(a)
    if s>m:
       m=s
print(s)
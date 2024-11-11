n = int(input())
s = 0
cot = 0
for _ in range(n):
    a,b=list( map(int, input().split(" ")))
    s += a* b
    cot += b
cot -= (1 )
cot +=  (s -1)//9
print(cot)

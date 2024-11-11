n=int(input())
num=0
for x in range(n):
    p,q=[int(y) for y in input().split()]
    if q>p:
        num+=1
print(num)

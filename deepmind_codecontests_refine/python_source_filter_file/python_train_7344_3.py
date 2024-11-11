n,b,d = [int(i) for i in input().split()]
orange =[int(i) for i in input().split()]
size=0
empty = 0
for i in range(n):
    if orange[i] <= d:
        size = size +orange[i]
    if size > d:
        size = 0
        empty +=1
print(empty)
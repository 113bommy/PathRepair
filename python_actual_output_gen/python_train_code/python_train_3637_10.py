import sys

read = input().split(" ")
n = int(read[0])
m = int(read[1])
mn = -sys.maxsize
for i in range(n):
    read = input().split(" ")
    a = int(read[0])
    b = int(read[1])
    if(a/b < mn):
        mn = a/b
print(a/b * m)
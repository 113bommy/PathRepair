a = int(input())
b = [int(x) for x in input().split()]
count = 0 
for i in b:
    count = count + max(b) - i
print (count)
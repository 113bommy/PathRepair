totalv = int(input())
a = list(map(int, input().split()))
orangev = 0
for i in a:
    orangev += ((i/100) * 1)
    
print(orangev/totalv)
n = int(input())
solutions = 0

while(n):
    sure = input().split(" ")
    if sure.count('1') >= 2:
        solutions += 1
        
    n -= 1
print(n)

    
n = int(input())
s = list(map(int, input().split()))
print(s)
x = 0
for i in s:
    x = x+i
print(x/n)
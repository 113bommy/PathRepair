import sys
input = sys.stdin.readline

t = int(input())

print(((t+1) * 4) - t)

print(0,0)
print(0,1)

for i in range(t):
    print(1+i, i)
    print(1+i, i+1)
    print(1+i, i+2)
    
print(i+2, i+1)
print(i+2, i+2)
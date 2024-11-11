import sys
input = sys.stdin.readline

X = int(input())
Num = X+1

while any(Num%i==0 for i in range(2,Num)):
    Num += 1

print(Num)
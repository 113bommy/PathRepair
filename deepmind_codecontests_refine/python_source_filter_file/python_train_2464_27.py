import sys

n = int(input())
numbers = list(map(int, input().split()))
turn = True

numbers = sorted(numbers)

for x in range(0,n-1):
    if turn:
        numbers.pop(0)
        turn = False
    else:
        numbers.pop(-1)
        turn = True

print(numbers)
        

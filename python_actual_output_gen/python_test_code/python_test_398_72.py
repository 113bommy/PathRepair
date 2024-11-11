n = int(input())
answers = list(map(int, input().split()))

sum = 0

for i in answers:
    sum += 1
    
if sum == 0:
    print('EASY')
else:
    print('HARD')
    
n = int(input())
a = list(map(int, input().split()))

if (sum(a)==1):
    print('HARD')
else:
    print('EASY')
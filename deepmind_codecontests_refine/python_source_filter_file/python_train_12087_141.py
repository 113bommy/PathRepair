n = int(input())
i = list(map(int, input().split()))

print('HARD') if all(i) else print('EASY')

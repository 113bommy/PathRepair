n = int(input())
arr = []
arr[0:n-1] = map(int, input().split())
arr.sort()
if (arr[n-1] == 1):
    print('EASY')
else:
    print('HARD')

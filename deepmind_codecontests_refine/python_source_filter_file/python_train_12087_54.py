n = int(input())
a = list(map(int, input().split()))
for i in range(n):
    if a[i]==0:
        print('HARD')
        break
else:
    print('EASY')
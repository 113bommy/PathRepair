n = int(input())
l = list(map(int,input().split()))
for i in range(1,3001):
    if i not in l:
        print(i)
        break
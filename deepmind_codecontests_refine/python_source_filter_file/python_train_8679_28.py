n=int(input())
a=list(map(int,input().split()))
for i in range(1,3001):
    if i not in a:
        print(i)
        break
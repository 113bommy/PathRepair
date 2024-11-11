n=int(input())
s=list(map(int,input().split()))
for i in range(1,4444):
    if i not in s:
        print(i)
        break

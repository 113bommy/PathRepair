
n = int(input())
a = [0 for i in range(3001)]
mp = map(int,input().split())
for k in mp:
    a[k]+=1
for i in range(1,3001):
    if a[i]==0:
        print(i)
        break

n = int(input())
a = [0 for i in range(3002)]
mp = map(int,input().split())
for k in mp:
    a[k]+=1
for i in range(1,3002):
    if a[i]==0:
        print(i)
        break
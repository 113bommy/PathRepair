n  = int(input())
li = list(map(int,input().split()))
a,b  = map(int,input().split())
c = b-a
y  = 0
for i in range(c):
    y += li[i]
print(y)
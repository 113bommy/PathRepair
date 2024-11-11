n = int(input())
rooms = 0
for i in range(n):
    p,q = list(map(int,input().split()))
    if p > q or p < q:
        rooms+=1
print(rooms)
    
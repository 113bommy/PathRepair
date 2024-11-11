n = int(input())
list = [10000000000]
for i in range(n):
    x, y = map(int,input().split())
    if min(x,y) <= list[-1] and max(x,y) >= list [-1]:
        list.append(min(x,y))
    if max(x, y) <= list[-1]:
        list.append(max(x, y))
print("YES" if len(list)-1 == n else "NO")
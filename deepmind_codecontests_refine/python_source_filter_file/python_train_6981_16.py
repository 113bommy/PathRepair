n = int(input())
data = [list(map(int,input().split())) for i in range(n)]
room = [[[0 for k in range(10)] for j in range(3)] for i in range(4)]
for a in data:
    room[a[0]-1][a[1]-1][a[2]-1]=a[3]

for x,i in enumerate(room):
    for j in i:
            print("".join(map(str,j)))
    if x <= 2 : print('#'*20)
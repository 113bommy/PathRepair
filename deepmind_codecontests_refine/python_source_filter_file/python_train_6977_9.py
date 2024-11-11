rooms = [[[0 for _ in range(10)] for _ in range(3)] for _ in range(4)]
n = int(input())
for _ in range(n):
    info = list(map(int,input().split()))
    rooms[info[0]-1][info[1]-1][info[2]-1] += info[3]

for b in range(4):
    for f in rooms[b] :
        print(" ".join(list(map(str,f))))
    if b != 3:
        print("#"*20)
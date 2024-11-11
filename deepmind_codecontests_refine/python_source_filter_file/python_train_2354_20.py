n = int(input())
a = list(map(int, input().split()))

cnt = 0

for i in a:
    cnt ^= (i & 1)

if cnt == 1:
    print("First")
else:
    print("Second")

h, w = map(int, input().split())
sum = 0
for i in range(h):
    a = input()
    sum += a.count('#')
if sum == h + w - 1:
    print("Possible")
else:
    print("Impossible")
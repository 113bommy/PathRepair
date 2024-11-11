def read():
    inputs = input().strip()
    return list(map(int, inputs.split()))
def read_pair():
    return map(int, input().split(' '))
n, s = read_pair()
mx = 0
for i in range (n):
    x, y = read_pair()
    mx = max(mx, x + y)
print(mx)
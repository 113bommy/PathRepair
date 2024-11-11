t = int(input())
for i in range(t):
    size = int(input())
    elements = input().split(' ')
    ordered = sorted(elements, key=lambda x: int(x), reverse=True)
    print(' '.join(elements))
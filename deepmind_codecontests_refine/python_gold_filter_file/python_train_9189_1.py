t = int(input())
def main():
    x1, y1, x2, y2 = map(int, input().split())
    if x1 == x2 and y1 == y2:
        print(0)
    elif x1 == x2 and y1 != y2:
        print(abs(y1 - y2))
    elif y1 == y2 and x1 != x2:
        print(abs(x1 - x2))
    else:
        print(1 + abs(x1 - x2) + abs(y1 - y2) + 1)
    
for i in range(t):
    main()
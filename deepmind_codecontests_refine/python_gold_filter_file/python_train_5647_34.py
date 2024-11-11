def printBoard(n,m):
    for i in range(n):
        for j in range(m):
            if i == 0 and j == 0:
                print("W", end = "")
            else: 
                print("B", end = "")
        print()

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n,m = map(int, input().split())
        printBoard(n,m)

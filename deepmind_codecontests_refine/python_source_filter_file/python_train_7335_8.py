
def main(n,a):
    x = [i for i in a if i >= 0]
    y = [-i for i in a if i < 0]
    print("X: ",x)
    print("Y: ",y)
    if sum(x)!=sum(y):
        winner = sum(y) > sum(x)
    else:
        winner = [j>i for i,j in zip(x,y) if j!=i]
        if winner != []:
            winner = winner[0]
        else:
            winner = a[-1] < 0
    print(["first","second"][winner])


def main_input():
    n = int(input())
    a = [int(input()) for i in range(n)]
    main(n,a)

if __name__ == "__main__":
    main_input()

main(5,[1,2,-3,-4,3])
main(3,[-1,-2,3])
main(2,[4,-4])
main(7,[1,2,-3,4,5,-6,7])

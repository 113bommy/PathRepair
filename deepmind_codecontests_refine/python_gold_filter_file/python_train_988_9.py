def main():
    n1,b1 = map(int,input().split())
    x = [int(i) for i in input().split()][::-1]
    n2, b2 = map(int, input().split())
    y = [int(i) for i in input().split()][::-1]
    xan,yan = 0,0
    for i , ii in enumerate(x):
        xan += ii*b1**i
    for i, ii in enumerate(y):
        yan += ii*b2** i
    if xan > yan:
        print(">")
    else:
        print("=" if yan == xan else "<")
if __name__ == '__main__':
    main()
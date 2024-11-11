def main():
    t = int(input())
    d = [[int(input()), [int(x) for x in input().split()]] for i in range(t)]

    s = True
    for c in d:
        s = True
        for i in range(1, c[0] - 1):
            if c[1][i-1] < c[1][i] and c[1][i] > c[1][i+1]:
                print("YES")
                print(i-1, i, i+1)
                s = False
                break
        if s:
            print("NO")






main()

def main():
    n, x,y = [int(v) for v in input().split()]
    val = [int(v) for v in input().split()]

    for i in range(1, len(val)):
        before = all([v > val[i] for v in val[i-x:i]])
        after = all([v > val[i] for v in val[i+1:i + y+1]])
        if before and after:
            print(i+1)
            return




if __name__ == "__main__":
    main()

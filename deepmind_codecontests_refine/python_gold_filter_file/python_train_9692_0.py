
def main():
    n, m = [int(v) for v in input().split()]
    min_x = m
    max_x = 0
    min_y = n
    max_y = 0
    for i in range(n):
        d = input()
        for j,c in enumerate(d):
            if c=="B":
                min_x = min(j+1, min_x)
                min_y = min(i + 1, min_y)
                max_x = max(j + 1, max_x)
                max_y = max(i + 1, max_y)
    print(min_y+(max_y-min_y)//2, min_x+(max_x-min_x)//2)




if __name__ == "__main__":
    main()

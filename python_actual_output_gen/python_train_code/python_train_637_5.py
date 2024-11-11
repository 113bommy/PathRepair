if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n,k = map(int, input().split())

        if (n-(k-1))&1 == 1 and (n-k-1) > 0:
            print('YES')
            print("1 "*(k-1) + str(n-(k-1)))
        elif (n-(k-1)*2) & 1 == 0 and (n-(k-1)*2) > 0:
            print('YES')
            print("2 "*(k-1) +str(n-(k-1)*2))
        else:
            print('NO')
        


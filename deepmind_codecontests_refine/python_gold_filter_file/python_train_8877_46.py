if __name__ == "__main__":
    t = int(input())
    while t:
        a,b,c,d = list(map(int, input().split()))
        print(max( min((a+b),(a+c)),(c+d) ))
        t = t - 1
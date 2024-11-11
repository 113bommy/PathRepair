from math import sqrt



def main():
    n = int(input())
    res = []
    if n==1:
        print(-1)
    else:
        for i in range(1, n+1):
            res.append(i+1 if i%2!=0 else i-1)
        print(" ".join([str(r) for r in res]))



if __name__ == "__main__":
    main()

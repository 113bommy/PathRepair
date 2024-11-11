if __name__ == "__main__":
    for i in range(int(input())):
        l, r, d = map(int, input().split())
        if(l < d):
            print(int(d*(int(r/d)+1)))
        else:
            print(d)
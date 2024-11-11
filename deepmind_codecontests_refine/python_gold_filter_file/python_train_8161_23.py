def main():
    a,b = [int(v) for v in input().split()]
    d = b//a
    d2 = b%a
    data = []
    for i in range(a):
        r = []
        for j in range(a):
            if i==j:
                r.append(d2+d)
            else:
                r.append(d)
        data.append(r)
    for d in data:
        print(" ".join([str(v) for v in d]))
if __name__ == "__main__":
    main()

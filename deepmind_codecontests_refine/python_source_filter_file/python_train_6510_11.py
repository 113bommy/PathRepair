def main():
    from collections import Counter
    input()
    aa = Counter(map(int, input().split()))
    m = int(input())
    bb, cc = (list(map(aa.__getitem__, map(int, input().split()))) for _ in (0, 1))
    print(max(_ for _ in zip(bb, cc, range(m)))[2] + 1)


    if __name__ == '__main__':
        main()

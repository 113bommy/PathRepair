for testCase in range(int(input())):
    n = int(input())
    s = input()
    if n == 2:
        print(0)
        continue
    print((s.count("00")+s.count("11"))//2)
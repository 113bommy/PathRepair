for _ in range(int(input())):
    s=[len(i)for i in input().split('0')]
    s.sort()
    print(sum(s[-1::-2]))
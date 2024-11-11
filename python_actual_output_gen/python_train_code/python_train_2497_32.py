for i in range(5):
    n = input().split(" ")
    if '1' in n:
        print(abs(2-i) + (n.index('1')-2))
def main():
    from collections import Counter as ct
    n = int(input())
    a = list(map(int, input().split()))
    c = ct(a)
    min_a = min(a)
    max_a = max(a)
    if min_a == 1:
        if c[min_a] == 1:
            pass
        elif a == [1, 1]:
            print("Possible")
            return 0
        else:
            print("Impossible")
            return 0
    if c[min_a] == 1 and (max_a+1)//2 > min_a:
        print("Impossible")
        return 0
    if c[min_a] == 2 and (max_a+2)//2 > min_a:
        print("Impossible")
        return 0
    if c[min_a] > 2:
        print("Impossible")
        return 0
    for i in range(min_a+1, max_a+1):
        if c[i] < 2:
            print("Impossible")
            return 0
    print("Possible")
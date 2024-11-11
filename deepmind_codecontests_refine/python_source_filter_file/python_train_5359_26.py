import math


def main():
    n, m = map(int, input().split(" "))
    line2 = list(map(int, input().split(" ")))
    line3 = list(map(int, input().split(" ")))
    happy_bois = line2[0]
    happy_girls = line3[0]
    if not (happy_bois and happy_girls):
        print("No")
        return
    happy_boi_set = set(line2[1:]) if len(line2) > 1 else set()
    happy_girl_set = set(line3[1:]) if len(line3) > 1 else set()
    for i in range(n * m // math.gcd(n, m)):
        if i % n in happy_boi_set or i % m in happy_girl_set:
            happy_boi_set.add(i % n)
            happy_girl_set.add(i % m)
        if len(happy_boi_set) == n and len(happy_girl_set) == m:
            print("Yes")
            return
    print("No")


main()
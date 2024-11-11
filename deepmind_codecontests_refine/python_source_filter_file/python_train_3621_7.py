def main():
    n = int(input())
    a = list(map(lambda x: int(x)-1, list(input())))
    b = [i % 2 for i in a]

    def all_a(x):
        ans = 0
        for j, i in enumerate(x):
            ans ^= (n-1 | j == n-1)*i
        return ans

    all_b = all_a(b)
    if all_b == 1:
        print(1)
        return
    if 1 in a:
        print(0)
        return
    b = [i//2 for i in a]
    return all_a(b)*2


main()
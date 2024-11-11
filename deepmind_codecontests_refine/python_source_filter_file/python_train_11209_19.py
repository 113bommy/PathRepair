from itertools import combinations

def main():
    n = int(input())
    a = [int(c) for c in input().split()]

    _sum = sum(a)
    for i in range(1, n):
        for comb in combinations(range(len(a)), i):
            first_sum = sum([a[e] for e in comb])
            second_sum = _sum - first_sum
            if first_sum != second_sum:
                print(len(comb))
                print(' '.join([str(a[j]) for j in comb]))
                return
            
    print(-1)


if __name__ == '__main__':
    main()

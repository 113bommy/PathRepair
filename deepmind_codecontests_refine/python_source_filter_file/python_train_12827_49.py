def main():
    n = int(input())
    sums = 0
    for i in range (1, n - 1):
        sums = sums + (1/i)
    print(sums)

main()
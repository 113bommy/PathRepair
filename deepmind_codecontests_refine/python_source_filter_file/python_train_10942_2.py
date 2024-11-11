def main():
    cases = [solve(case) for case in [tuple(map(int, input().split()))
                                      for _ in range(int(input()))]]
    # print(cases)
    # solve((1, 2, 3, 4))


def solve(case):
    money, offer_number, free_number, cost = case
    print(money//(offer_number*cost)*(offer_number+free_number) +
          (money % (offer_number*cost)*cost))


main()

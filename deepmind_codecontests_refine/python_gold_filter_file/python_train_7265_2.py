import sys

input = sys.stdin.readline


# https://atcoder.jp/contests/agc039/submissions/7878237
class AtCoder:
    def main(self):
        N = int(input())
        X = input().rstrip()

        k_cycles = 0
        ans = 0
        L = []
        for k in self.make_divisors(N):
            if (N // k) % 2 != 0:
                first_k_bit = X[:k]
                first_k_bit_ = first_k_bit.replace("0", "2").replace("1", "0").replace("2", "1")
                check_target = first_k_bit + (first_k_bit_ + first_k_bit) * ((N // k - 1) // 2)
                k_cycle = int(first_k_bit, 2) + (int(check_target, 2) <= int(X, 2))

                for l, cnt in L:
                    if k % l == 0:
                        k_cycle -= cnt
                L.append((k, k_cycle))

                k_cycles += k_cycle
                ans += 2 * k * k_cycle

        ans += (int(X, 2) + 1 - k_cycles) * 2 * N

        print(ans % 998244353)

    def make_divisors(self, n: int):
        divisors = []
        for i in range(1, int(n ** 0.5) + 1):
            if n % i == 0:
                divisors.append(i)
                if i != n // i:
                    divisors.append(n // i)

        divisors.sort()
        return divisors


# Run main
if __name__ == '__main__':
    AtCoder().main()

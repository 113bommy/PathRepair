def main():
    n, m , k = map(int, input().split())
    A = list(map(int, input().split()))
    m1 = max(A)
    A.pop(A.index(m1))
    m2 = max(A)
    l = m // k
    sum1 = m1 * m
    sum1 -= (k + 1) * (m1 - m2)
    print(sum1)
main()
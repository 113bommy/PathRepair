import math
import sys

lines = sys.stdin.readlines()


def read_three_nums(line):
    [n1, n2, n3] = list(map(int, line.strip().split(" ")))
    return n1, n2, n3


def get_divisors(num):
    divisors = []
    for i in range(1, int(math.sqrt(num)) + 1):
        if num % i == 0:
            divisors.append(i)
            divisors.append(num / i)
    return divisors


n, m, k = read_three_nums(lines[0])

target_area = n * m / k
if target_area % 0.5 != 0:
    print("NO")
else:
    h = 2 * m / k
    h2 = 2 * n / k
    min_area_with_n = n / 2
    min_area_with_m = m / 2

    if h % 1 == 0:
        print("YES")
        print(f"0 0")
        print(f"{n} 0")
        print(f"0 {int(h)}")
    elif h2 % 1 == 0:
        print("YES")
        print(f"0 0")
        print(f"{int(h2)} 0")
        print(f"0 {m}")
    elif target_area < min_area_with_n:
        w = target_area * 2
        if w % 1 == 0:
            print("YES")
            print(f"0 0")
            print(f"{int(w)} 0")
            print(f"0 1")
        else:
            print("NO")
    elif target_area < min_area_with_m:
        w = target_area * 2
        if w % 1 == 0:
            print("YES")
            print(f"0 0")
            print(f"1 0")
            print(f"0 {int(w)}")
        else:
            print("NO")
    else:
        m_divisors = get_divisors(m)
        n_divisors = get_divisors(n)
        for i in m_divisors:
            for j in n_divisors:
                if i * j / 2 == target_area:
                    print("YES")
                    print(f"0 0")
                    print(f"{int(i)} 0")
                    print(f"0 {int(j)}")
                    sys.exit()
        print("NO")
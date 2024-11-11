from sys import stdin, stdout

int_in = lambda: int(stdin.readline())
arr_in = lambda: [int(x) for x in stdin.readline().split()]
mat_in = lambda rows: [arr_in() for y in range(rows)]
str_in = lambda: stdin.readline().strip()
out = lambda o: stdout.write("{}\n".format(o))
arr_out = lambda o: out(" ".join(map(str, o)))
bool_out = lambda o: out("YES" if o else "NO")


if __name__ == "__main__":
    n = int_in()
    mod = pow(10, 9) + 7

    out(((pow(3, n, 4 * mod) + 3 * pow(-1, n)) // 4) % mod)
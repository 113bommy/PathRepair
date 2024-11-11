from sys import stdin, stdout

int_in = lambda: int(stdin.readline())
arr_in = lambda: [int(x) for x in stdin.readline().split()]
mat_in = lambda rows: [arr_in() for _ in range(rows)]
str_in = lambda: stdin.readline().strip()
out = lambda o: stdout.write("{}\n".format(o))
arr_out = lambda o: out(" ".join(map(str, o)))
bool_out = lambda o: out("YES" if o else "NO")
tests = lambda: range(1, int_in() + 1)
case_out = lambda i, o: out("Case #{}: {}".format(i, o))


def solve(n, r):
    if r > n:
        return (n * (n - 1) // 2) + 1
    
    return (r * (r + 1) // 2)



if __name__ == "__main__":
    for _ in tests():
        n, r = arr_in()
        out(solve(n, r))
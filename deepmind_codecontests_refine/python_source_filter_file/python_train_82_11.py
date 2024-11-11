T = int(input())
ABCD = [ list(map(int,input().split())) for _ in range(T)]
import fractions

def check(a,b,c,d):
    if b > d or a < b:
        print("No")
        return
    elif c >= b:
        print("Yes")
        return
    def_a = a % b
    a = def_a
    while True:
        a = (a + d) % b
        if a > c:
            print("No")
            return
        g = fractions.gcd(b,d)
        f = (b -a) // g
        if (b - a) % g == 0:
            f -= 1
        if g == 0 or c <= a + f * g:
            print("Yes")
            return
        print("No")
        return

for abcd in ABCD:
    check(abcd[0],abcd[1],abcd[2],abcd[3])

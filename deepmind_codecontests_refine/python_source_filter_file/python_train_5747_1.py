import sys 

def main():
    n = sys.stdin.readline()
    return int(n)

def gcd(a, b):
    if a > b:
        r = a % b
        if r == 0:
            return b 
        a = r 
        return gcd(max(a,b), min(a,b))
    else:
        r = b % a
        if r == 0:
            return a  
        b = r
        return gcd(max(a,b), min(a,b)) 

def solve(n):
    run = None 
    cap = int(n ** 0.5)
    for x in range(2, cap + 1):
        if n % x == 0:
            if run == None:
                run = x
            comp = n / x 
            run = gcd(max(run, x), min(run, x))
            run = gcd(max(run, comp), min(run, comp))
    if run is None:
        return n
    return run

res = solve(main())
sys.stdout.write(str(res)+"\n")
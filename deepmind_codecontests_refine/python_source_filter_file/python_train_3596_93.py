import math

def main():
    n, x = map(int, input().split())
    d = 0
    for _ in range(n):
        op, amt = input().split()
        amt = int(amt)
        if op == "+":
            x += amt
        elif op == "-":
            if amt >= x:
                d += 1
            else:
                x -= amt

    print(x, d)
            

if __name__ == "__main__":
    main()

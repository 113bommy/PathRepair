def main():
    t = int(input())

    for i in range(t):
        a,b,c,r = map(int, input().split())

        c1 = c - r
        c2 = c + r

        if b < a:
            temp1 = a
            a = b
            b = temp1
        
        if c2 <= a or c1 >= b:
            print(abs(b-a))
            continue
        if c2 > b and c1 < a:
            print(0)
            continue
        if c2 < b and c1 > a:
            print(abs(a - b) - abs(c2-c1))
            continue
        if c1 < a and c2 < b:
            print(abs(c2 - b))
            continue
        if c1 > a and c2 > b:
            print(abs(c1 - a))
            continue


        
main()

def main():
    q = int(input())
    for i in range(q):
        n,a,b = map(int,input().split())
        if 2*a <= b:
            print (n*a)
        else:
            if n%2 == 0:
                print (int((n*b)/2))
            else:
                cost = int(n/2)*b
                cost += a
                print (cost)

main()
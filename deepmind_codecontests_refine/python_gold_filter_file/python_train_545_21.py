from sys import stdin,stdout
input = stdin.readline

def main():
    #t = int(input())
    t=1
    for i in range(t):
        n = int(input())
        #n1, n2, k1, k2 = map(int,input().split())
        ai = list(map(int,input().split()))
        if n == 1:
            print(1,1)
            print(0)
            print(1,1)
            print(0)
            print(1,1)
            print(int(-ai[0]))
            return
        print(1,n)
        n2 = n * (n-1)
        ai2 = [n * (n-1-i%(n-1)) for i in ai]
        print(*ai2)
        ai = [ai[i]+ai2[i] for i in range(n)]
        print(1,1)
        print(int(-ai[0]))
        print(2,n)
        print(*[int(-ai[i]) for i in range(1,n)])
main()


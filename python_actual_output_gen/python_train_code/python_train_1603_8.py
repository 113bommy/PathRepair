def solve():
    n1,k1 = map(int,input().split())
    print(n1+k1)
        

tests = int(input())
while tests:
    tests-=1
    print(solve())

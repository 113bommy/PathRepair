def solve():
    n = int(input())
    mS = 0
    cS = 0
    for i in range(n):
        m,c = map(int,input().split())
        if m > c:
            mS +=1  
        elif c > m:
            cS += 1
    if mS > cS:
        print("Mishka")
    elif mS==cS:
        print("Friendship is magic!^^")
    else:
        print("Chris")
# n,c = map(int,input().split())
# a = int(input())
# b = int(input())
# c = int(input())
# l = list(map(int,input().split()))
# s = input()
# print(solve(n,c,l))
solve()




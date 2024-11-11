def testcase():
    n = int(input())
    if n <= 2:
        return 0
    return n//2


for _ in range(int(input())):
    print(testcase())

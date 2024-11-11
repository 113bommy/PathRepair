# for testCase in range(int(input())):
n = int(input())
per = list(map(int ,input().split()))
print(max(per.index(1) ,per.index(n) ,n-per.index(1) ,n-per.index(n))-1)

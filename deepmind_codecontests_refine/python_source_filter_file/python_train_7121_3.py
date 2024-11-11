n = int(input())
a = list(map(int, input().split()))

# Count number of 5 and 0
num5 = a.count(5)
num0 = a.count(0)

# Count largest number of 5 can put into the answer
if num0 == 0:
    print(-1)
elif num5 < 9:
    print(0)
else:
    temp = num5 % 9
    ans = '5' * temp + '0' * num0
    print(ans)

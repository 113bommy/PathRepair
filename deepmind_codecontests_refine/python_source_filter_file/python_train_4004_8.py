def scan(type):
    return list(map(type, input().split()))
a,b,c = scan(int)

def digitSum(x):
    if (x//10 == 0):
        return x%10
    return x%10 + digitSum(x//10)

ans = []

for s in range(1,73):
    x = b*s**a + c
    # print(s,x,x>0,digitSum(x))
    if (x > 0 and x < 10**9 and digitSum(x) == s):
        ans.append(x)

print(len(ans))
print(*ans)

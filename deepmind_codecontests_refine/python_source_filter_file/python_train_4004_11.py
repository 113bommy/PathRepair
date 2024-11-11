def s(x):
    tmp = x
    ans = 0
    while tmp > 0:
        ans += tmp % 10
        tmp //= 10
    return ans

def main(a, b, c):
    ans = []
    for i in range(82):
        x = b * (i ** a) + c
        if 0 <= x <= 10 ** 9 and s(x) == i:
            ans.append(x)
    print(len(ans))
    for i in ans:
        print(i, end = ' ')

a, b, c = map(int, input().split()) 
main(a, b, c)

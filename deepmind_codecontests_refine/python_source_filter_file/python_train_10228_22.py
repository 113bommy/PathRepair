def check(a, b):
    if a < b:
        return "NO"
    Sum = (a-(b-1)*(2*b-2)//2)
    if  Sum%2==1 and Sum>0 and Sum > 1+(b-1)*2:
        return "YES"
    return "NO"

t = int(input())
for i in range(t):
    a = list(map (int, input().strip().split()))
    print(check(a[0], a[1]))
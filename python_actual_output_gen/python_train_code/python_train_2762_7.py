for _ in range(int(input())):
    N = int(input())
    a = N//4
    rem = N%4
    if rem > 0:
        ans = '9'*(N-a-1)
    else:
        ans = '9'*(N-a)
    if 0<rem<4:
        ans += '8'
    print(ans+'0'*a)

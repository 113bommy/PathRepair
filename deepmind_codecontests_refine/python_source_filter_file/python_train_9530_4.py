count = int(input())

def run():
    for _ in range(count):
        b, a = (int(x) for x in input().split()[1:])
        if a > b > 2400:
            print('YES')
            return
    print('NO')
run()
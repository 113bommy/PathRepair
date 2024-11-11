# Bismillah
# Status: Own Solve

def King_Aurther():
    a, b = map(int, input().split())

    if(a == 0 and b == 0):
        print('Here')
        return
    elif(a == b):
        print('1')
    elif(abs(a-b) % 2 == 0):
        print('2')
    else:
        print('-1')


def main():
    Test_case = int(input())
    for x in range(Test_case):
        King_Aurther()


main()

def solve2(num):
    if num<9:
        return 0
    elif num==9:
        return 1

    return (num+1)//10
def digits_sum():
    t=int(input())
    for i in range(t):
        num=int(input())
        print(solve2(num))
digits_sum()

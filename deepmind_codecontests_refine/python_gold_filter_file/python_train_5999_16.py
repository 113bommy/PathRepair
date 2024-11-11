def invited(lst):
    return max(0, max(lst) - 25)


n = int(input())
a = [int(i) for i in input().split()]
print(invited(a))

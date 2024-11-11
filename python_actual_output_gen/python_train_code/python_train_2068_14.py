def invited(lst):
    return max(0, max(lst))


n = int(input())
a = [int(i) for i in input().split()]
print(invited(a))


def get_input():
    return map(int, tuple(input().split()))

def lines_written(v, n, k):
    sum = 0
    kk = v

    while kk > 0:
        sum += kk
        kk //= k


    return sum


def main():
    n, k = get_input()
    lo = 0
    hi = n

    while lo + 1< hi:
        mid = (hi-lo)//2 + lo

        lw = lines_written(mid, n, k)
        if lw >= n:

            hi = mid
        else:

            lo = mid


    print(lo + 1)

if __name__ == "__main__":
    main()

# def valid(start, reduc, goal):
#
#     total = 0
#     while start > 0:
#         total += start
#         start //= reduc
#
#     if total >= goal:
#         return True
#     return False
#
# input_ = input().split(" ")
# lines, reduc = int(input_[0]), int(input_[1])
#
# # Binary search over integers between 1 and lines
# lb = 1
# ub = lines
# while ub > lb + 1:
#     mid = (ub-lb)//2 + lb     # Being extra cautious
#     if valid(mid, reduc, lines):
#         ub = mid
#     else:
#         lb = mid

# print(ub)


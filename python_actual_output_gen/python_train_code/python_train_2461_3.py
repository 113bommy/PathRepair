import sys
input = sys.stdin.readline
def multi_input():
    return map(int, input().split())

def array_print(arr):
    print(' '.join(map(str, arr)))

def code_line(total,n,k):
    line = n
    new_line = int(n/k)
    while line<total and new_line>0:
        line += new_line
        new_line = int(new_line/k)


    if line >= total:
        return True
    else:
        return False

def bs(total, k):
    left = 1
    right = total
    prev = total
    while left<right:
        mid = (left + right) //2
        if code_line(total,mid,k):
            prev = mid
            right = mid -1
        else:
            left = mid + 1

    return prev

total, k = multi_input()
print(bs(total, k))

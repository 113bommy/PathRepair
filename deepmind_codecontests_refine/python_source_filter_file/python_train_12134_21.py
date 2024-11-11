"""Codeforces problem 702A"""

def main():
    """Dynamic programming"""
    tmp = input()
    numbers = list(map(int, input().split()))
    cur_sum = 1
    max_sum = 1
    for i in range(1, len(numbers)):
        if numbers[i] > numbers[i-1]:
            cur_sum = cur_sum + 1
        else:
            if max_sum < cur_sum:
                max_sum = cur_sum
                cur_sum = 1
    if max_sum < cur_sum:
        print(cur_sum) 
    else:
        print(max_sum)

if __name__ == '__main__':
    main()

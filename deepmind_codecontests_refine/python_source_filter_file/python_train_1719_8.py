# program to find longest regular bracket sequence and their counts
# 
def LongestBracketSequence(s):
    """function calculates the longest bracket sequence and their counts when s string is given"""
    stack = []
    arr = [0]*len(s)
    max, sum, count = [0, 0, 0]
    longest_count = 0
    for i in range(len(s)):
        ch = s[i]
        if ch == '(':
            stack.append('(')
        elif ch == ')' and len(stack) != 0:
            top = stack[-1]
            if top == '(':
                stack.pop()
                arr[i] = 2

    for value in reversed(arr):
        if value == 2:
            if count < 0:
                count = 1
                if max < sum:
                    max = sum
                    longest_count = 1
                elif max == sum:
                    longest_count += 1
                sum = 2
            else:
                count += 1
                sum += 2
        else:
            count -= 1
            if count == -1:
                if max < sum:
                    max = sum
                    longest_count = 1
                elif max == sum:
                    longest_count += 1
                sum = 0
    
    if count == 0 and sum > 0:
        if max < sum:
            max = sum
            longest_count = 1
        elif max == sum:
            longest_count += 1
    if max == 0:
        longest_count = 1
    print(str(max) + str(longest_count))


s = input()
LongestBracketSequence(s)
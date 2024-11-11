import sys
from collections import Counter
import math
import bisect
import heapq
#sys.stdin = open("input.txt")
from itertools import combinations
from collections import defaultdict

num_cases = int(sys.stdin.readline().strip())


for case in range(1, num_cases+1):
    N = int(sys.stdin.readline().strip())
    S = str(sys.stdin.readline().strip())

    if N == S.count("?"):
        if N % 2 == 0:
            print('BR' * (N//2))
        else:
            print('R' + 'BR' * (N // 2))

    else:
        if S[0] == '?':
            left_thing = "0"
            left_pos = -1
            for i in range(len(S)):
                if S[i] != '?':
                    left_thing = S[i]
                    left_pos = i
                    break
            if left_thing == 'R':
                num_question = left_pos
                if num_question % 2 == 0:
                    S = 'RB' * (num_question//2) + S[left_pos:]
                else:
                    S = 'B' + 'RB' * (num_question//2) + S[left_pos:]
            else:
                num_question = left_pos
                if num_question % 2 == 0:
                    S = 'BR' * (num_question // 2) + S[left_pos:]
                else:
                    S = 'R' + 'BR' * (num_question // 2) + S[left_pos:]
        S = S[::-1]
        if S[0] == '?':
            left_thing = "0"
            left_pos = -1
            for i in range(len(S)):
                if S[i] != '?':
                    left_thing = S[i]
                    left_pos = i
                    break
            if left_thing == 'R':
                num_question = left_pos
                if num_question % 2 == 0:
                    S = 'RB' * (num_question//2) + S[left_pos:]
                else:
                    S = 'B' + 'RB' * (num_question//2) + S[left_pos:]
            else:
                num_question = left_pos
                if num_question % 2 == 0:
                    S = 'BR' * (num_question // 2) + S[left_pos:]
                else:
                    S = 'R' + 'BR' * (num_question // 2) + S[left_pos:]
        S = S[::-1]

        stack = 0
        result = ''
        for i in range(len(S)):
            if S[i] != '?':
                if stack == 0:
                    result += S[i]
                else:
                    most_left = result[-1]
                    most_right = S[i]
                    if most_left == most_right:
                        if most_left == 'R':
                            if stack % 2 == 0:
                                result += 'BR' * (stack//2)
                            else:
                                result += 'BR' * (stack // 2) + 'R'
                        else:
                            if stack % 2 == 0:
                                result += 'RB' * (stack//2)
                            else:
                                result += 'RB' * (stack // 2) + 'B'
                    else:
                        if most_left == 'R':
                            if stack % 2 == 0:
                                result += 'BR' * (stack//2)
                            else:
                                result += 'BR' * (stack // 2) + 'B'
                        else:
                            if stack % 2 == 0:
                                result += 'RB' * (stack//2)
                            else:
                                result += 'RB' * (stack // 2) + 'R'
                    result += S[i]
                    stack = 0
            else:
                stack += 1
        print(result)


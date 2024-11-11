
# https://codeforces.com/problemset/problem/1539/A
# A. Contest Start

# Input :-
# 4
# 4 2 5
# 3 1 2
# 3 3 10
# 2000000000 1 2000000000

# Output :- 
# 5
# 3
# 3
# 1999999999000000000

test_cases = int(input())
for _ in range(test_cases):
    no_candidates, interval, each_duration = list(map(int, input().split()))
    # for each candidate, we have to count the people who start in the range 
    # [interval+i, interval+each_duration+i]
    # This is same as counting the number of multiples of x in [0, each_duration]
    # -> (each_duration/interval)

    # But for the last (each_duration/interval) candidates, 
    # this is not the case because there isn't infinite candidates
    # ex:- last candidate scores 0, second last scores 1, ....
    # so for last (each_duration/interval) candidates, the counting should be :-
    # ( 0 + 1 + 2 + .... + ((each_duration/interval)-1) )
    point_of_change_from_last = min(no_candidates, each_duration//interval)
    # batch 1 score -
    score = (no_candidates - point_of_change_from_last) * (each_duration//interval)
    
    # batch 2 score -
    score += (point_of_change_from_last - 1) * (point_of_change_from_last)/ 2
    # sum to point_of_change - 1

    print(int(score))


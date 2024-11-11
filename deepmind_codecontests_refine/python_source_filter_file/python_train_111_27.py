# https://codeforces.com/problemset/problem/1043/A

n = int(input())

votes = tuple(map(int, input().split()))

max_vote = max(votes)

total_elodreip = sum(votes)

total = 0

for i in votes:
    total += (max_vote - i)

while total < total_elodreip:
    total += n
    max_vote += 1

print(max_vote)
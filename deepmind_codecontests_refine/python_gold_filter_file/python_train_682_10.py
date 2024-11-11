'''
http://codeforces.com/problemset/problem/779/A
'''

n = int(input())
groupA = list(map(int, input().split()))
groupB = list(map(int, input().split()))

def num_switches(n, groupA, groupB):
    diff = [0, 0, 0, 0, 0]
    for score in range(1, 6):
        if abs(groupA.count(score) - groupB.count(score)) % 2 == 1:
            return -1
        else:
            diff[score - 1] = abs(groupA.count(score) - groupB.count(score))
    if sum(diff) % 4 != 0:
        return -1
    else:
        return sum(diff) // 4



print(num_switches(n, groupA, groupB))

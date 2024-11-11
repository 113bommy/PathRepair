import sys

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

ans = 0
answered = 0
for choices in a:
    ans += (choices)*(answered+1)
    answered += 1
print(ans-1)
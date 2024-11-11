# import sys

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')


n = int(input())
s = list(map(int, input().split()))

pref = [0]*n
pref[0] = s[0]
for i in range(1, n):
    pref[i] = (pref[i-1]+s[i])
pref = [0] + pref
print(pref)

q = int(input())
while q:
    q -= 1

    l, r = list(map(int, input().split()))
    # b = list(map(int, input().split()))
    # s = input()
    print((pref[r]-pref[l-1])//10)
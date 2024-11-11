from sys import stdin
inp = stdin.readline
n = int(input(),2)
count = 0
while True:
    if count**4>=n:
        break
    count += 1
print(count)
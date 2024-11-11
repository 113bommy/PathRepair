from functools import reduce

n, k = list(map(int, input().split()))
passwords = []

for _ in range(n+1):
    passwords.append(input())

correctPassword = passwords[n]
passwords = passwords[:-1]
passwords.sort()


sortedByLength = {}
for password in passwords:
    if len(password) not in sortedByLength.keys():
        sortedByLength.update({len(password): 1})
    else:
        sortedByLength[len(password)] += 1

minTries = 1

keys = list(sortedByLength.keys())
keys.sort()

for i in keys:
    if i < len(correctPassword):
        minTries += sortedByLength[i]

maxTries = minTries + sortedByLength[len(correctPassword)] - 1

minTime = minTries + int((minTries-1)/k)*5
maxTime = maxTries + int((maxTries-1)/k)*5

print(minTime, maxTime)

"""
Codeforces Contest 596 Problem B
Wilbur and Array

Tags:
Greedy

TsFreddie - wyffaddy


"""

n = input() # useless

if n == "0":
    print(0)
    quit()

data = input()
data = data.split(" ")
for i in range(len(data)):
    data[i] = int(data[i])

ans = data[0]
for i in range(len(data) - 1):
    n = i + 1
    ans += abs(data[n] - data[n - 1])

print(ans)

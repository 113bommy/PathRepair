# Little Pony and Crystal Mine
# http://codeforces.com/problemset/problem/454/A

n = int(input())

string = "D"

x=1
while x < n:
    print(string.center(n,"*"))
    string = string + "DD"
    x = x + 2
# print(string + "DD")
while x > 1:
    string = string[:-2]
    print(string.center(n,"*"))
    x = x - 2

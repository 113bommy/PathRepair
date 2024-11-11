def good(n):
    for i in range(n):
        a, b, c = (s for s in input().split())
        if int(b) >= 2500 and int(c) > int(b):
            return "YES"
    return("NO")

n =  int(input())
print(good(n))
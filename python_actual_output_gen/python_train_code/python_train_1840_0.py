T = int(input())
for i in range(T):
    n,s,t = [int(i) for i in input().split()]
    if n == s == t:
        print(1)
    else:
        print(min(s,t)+1)

t = int(input())
cnt = 0
while t:
    n = input()
    print(n)
    if n.count('1') >= 2:
        cnt += 1
        print(cnt)
    t -= 1
print(cnt)

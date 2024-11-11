n = input()
a = list(map(int, input().split()))
cnt = 0
while all(i%2==0 for i in a):
    a = [i/2 for in a]
    cnt += 1
print(cnt)

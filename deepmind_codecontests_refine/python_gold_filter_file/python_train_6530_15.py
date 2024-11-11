# 00101101001
n, x, y = map(int, input().split())
line = input()
temp = line.split('1')
cnt = 0
#print(temp)
for i in temp:
    if len(i) > 0:
        cnt += 1
print(min(y*cnt, abs(y+x*(cnt-1))))

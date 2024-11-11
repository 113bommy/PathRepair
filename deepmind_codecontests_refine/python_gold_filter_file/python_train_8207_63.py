x = int(input())
cnt = (x//11)*2
k = x%11
if k>6:
    cnt += 2
elif 0<k<7:
    cnt += 1
print(cnt)
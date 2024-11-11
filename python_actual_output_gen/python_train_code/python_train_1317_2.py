n = int(input())
months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

a = list(map(int, input().split()))
done = False
for i in range(len(months)):
    mnt = i
    cnt = 0
    leaped = False
    for j in range(len(a)):
        if months[mnt%12] == a[j] or (not leaped and mnt == 1 and months[mnt%12]+1 == a[j]):
            if (mnt == 1 and months[mnt%12]+1 == a[j]):
                leaped = True
            mnt += 1
            cnt += 1
        else:
            break
    if cnt == len(a):
        done = True
        break

print ("Yes" if done else "No")

input()
a=[*map(int,input().split())]
s = [sum(a[::2]) , sum(a[1::2])]
print(s)
cnt = i = 0
a = [0] + a
for j in range(1 , len(a)):
     s[i]+=a[j - 1]-a[j]
     if s[0] == s[1]:
          cnt += 1
     i = not(i)
print(cnt)

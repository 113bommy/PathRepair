s = input()
k = int(input())
s1 = s[:]
cnt = 0
while s1 != '':
    s1 = s1.replace(s1[0],'')
    cnt +=1
if k - cnt > 26 - cnt or k > len(s):
    print('impossible')
elif cnt == k:
    print('0')
else:
    print(abs(k - cnt))

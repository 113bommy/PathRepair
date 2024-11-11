n = int(input())
s = input()
cnt = 0
for i in s:
    if i == 'A':
        cnt += 1
if cnt == (n-cnt):
    print("Friendship")
elif cnt > (n-cnt):
    print("Anton")
else:
    print("Danik")
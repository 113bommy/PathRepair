num = int(input())
s = input()[::-1]
n = bin(int(s,2) + 1)
ss = n[2:]
ans = 0


if len(ss)< len(s):
    ss = "0"*(len(s)-len(ss)) + ss
elif len(ss) > len(s):
    ss = ss[1:]

for i, j in zip(s, ss):
    if i != j :
        ans +=1


print(ans)
# print(s)
# print(ss)

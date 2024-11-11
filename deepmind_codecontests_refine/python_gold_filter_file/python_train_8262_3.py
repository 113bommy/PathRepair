n = int(input())
l = list(map(int, input().split()))
s = set(l)-{0}
ans =0
for i in s:
    #print(i)
    if l.count(i) ==2:
        #print(i)
        ans = ans +1
    if l.count(i) >2:
        #print(i)
        ans = -1
        break
print(ans)
a = input()
n = len(a)

ans = []
cnt = 1
m = 1  #for max
mm = 0 #for min
ans.append(1)
for i in range(1,n):
    if(a[i] == a[0]):
        cnt+=1
    else:
        cnt -=1
    ans.append(cnt)

    m = max(m,cnt)
    mm = min(mm,cnt)
# print(ans)
print(m+mm)


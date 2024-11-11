

n  = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))


ans = 0
for i in range(n):
    ans+= (b[i]*a[i])
maxi = ans


for i in range(n):
    l = i - 1
    r = i + 1
    temp_ans = ans
    while l >= 0 and r < n:
        temp_ans = temp_ans - (a[r]-a[l])*(b[l]-b[r])

        maxi = max(maxi, temp_ans)
        l -= 1
        r += 1
    l = i
    r = i+1
    temp_ans = ans
    while l>=0 and r<n:
        temp_ans = temp_ans -(a[r]-a[l])*(b[l]-b[r])
        # print("temp_ans", temp_ans)
        maxi = max(maxi,temp_ans)
        l-=1
        r+=1
print(maxi)
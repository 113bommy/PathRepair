ans=[0]
for i in range(1,31625):
    ans.append(i**2-i+1)
for _ in range(int(input())):
    k = int(input())
    for i in range(1,31625):
        if ans[i - 1] <= k < ans[i]:
            temp = ans[i] - i + 1
            if k < temp :
                temp = k - ans[i-1]
                print(i-1, i-1-temp)
            else:
                temp = ans[i] - k
                print(i-temp, i)
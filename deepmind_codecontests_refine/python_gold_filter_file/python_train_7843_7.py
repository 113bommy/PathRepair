n = int(input())
ans = 0
for i in range(1,int(n**.5) +1):
    if n % i == 0 :
        ans += int(any(j in str(n) for j in str(i)))
        tmp = n//i
        if i != tmp:
            ans  += int(any(j in str(n) for j in str(tmp)))
 
print(ans)
        
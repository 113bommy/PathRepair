s = str(input())
k = int(input())
l = list(map(int, input().split()))
numbers = []
for i in range(len(s)):
    numbers.append(l[ord(s[i])-97])
high = max(numbers)
while k!=0:
    numbers.append(high)
    k=k-1
temp=1
ans= 0
for i in numbers:
    ans = ans + temp*i
    temp = temp+1
print(ans)

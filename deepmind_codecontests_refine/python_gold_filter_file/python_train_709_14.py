N = int(input())
A = list(map(int,input().split()))
odd = 0
even4 = 0
for i in A :
    if not i % 4 :
        even4 += 1
    elif i % 2 :
        odd += 1
if (odd <= even4) or (N//2 <= even4) :
    ans = "Yes"
else :
    ans = "No"
print(ans)

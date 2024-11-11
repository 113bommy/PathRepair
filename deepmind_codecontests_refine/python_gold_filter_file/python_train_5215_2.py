s = input()
sumarr = [int(s[0])]
for i in range(1, len(s)):
    sumarr.append(sumarr[i - 1] + int(s[i]))
ansarr = [0 for _ in range(len(s))]
if not (sumarr[0] % 3):
    ansarr[0] = 1
else:
    ansarr[0] = 0
for i in range(1, len(s)):
    ansarr[i] = ansarr[i - 1]
    j = 1
    while ((i - j) >= 0) and ((sumarr[i] - sumarr[i - j]) % 3): 
        j += 1
    if j <= i:
        ansarr[i] = max(ansarr[i], ansarr[i - j] + 1)
    else:
        if ((sumarr[i]) % 3) == 0:
            ansarr[i] = max(ansarr[i], 1)
print(ansarr[len(ansarr) - 1])
n, b = map(int, input().split())
i = 2;
div = []
cnt = []
b1 = b
while (i * i <= b1):
    if (b1 % i == 0):
        div.append(i);
        cnt.append(0);
        while (b1 % i == 0):
            cnt[-1] += 1;
            b1 /= i;
    i+= 1;
if (b1 != 1):
    div.append(b1);
    cnt.append(1);
for i in range(len(div)):
    curr = div[i];
    cnt1 = cnt[i];
    ans1 = 0;
    while (curr <= n):
        ans1 += n // curr;
        curr *= div[i];
    if (i == 0) :
        ans = ans1 // cnt1
    else:
        ans = min(ans, ans1 // cnt1);
print(int(ans))
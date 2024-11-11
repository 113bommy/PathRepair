n, k = map(int, input().split())
l = list(map(int, input().split()))
i = 2;
cnt = 0;
l.sort();
while i < n:
    if(l[i - 1] + k <= 5) : cnt = cnt + 1;
    i += 3;
print(cnt);